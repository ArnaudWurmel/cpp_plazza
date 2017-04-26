//
// Process.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:06 2017 Arnaud WURMEL
// Last update Wed Apr 26 03:41:27 2017 Arnaud WURMEL
//

#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <memory>
#include <map>
#include <functional>
#include <utility>
#include <cstring>
#include "Logger.hh"
#include "Command.hh"
#include "Thread.hh"
#include "ThreadTask.hh"
#include "ThreadPool.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "Pipe.hh"
#include "AProcess.hh"
#include "Process.hh"
#include "ThreadTask.hh"
#include "Errors.hh"

unsigned int	plz::Process::processId = 0;

plz::Process::Process(unsigned int maxThread)
{
  _pid = -1;
  _maxThread = maxThread;
  _lastUpdate = 0;
  std::string	pipePath = "/tmp/" + std::to_string(plz::Process::processId);
  _in = std::shared_ptr<APipe>(new Pipe(pipePath + ".in.fifo"));
  _in->openPipe();
  _out = std::shared_ptr<APipe>(new Pipe(pipePath + ".out.fifo"));
  _out->openPipe();
  plz::Process::processId += 1;
  _pid = fork();
  if (_pid == -1)
    {
      std::cerr << "plz: Failed to add new process." << std::endl;
      throw Error("Failed to add process");
    }
  if (_pid != 0)
    Logger::addLog("plz: Process [" + std::to_string(_pid) + "] created.");
  else
    {
      runProcess();
      exit(0);
    }
}

void	plz::Process::runProcess()
{
  PipeData	data;
  std::map<PipeData::DataType, std::function<void (PipeData const&)> > functionPtr;

  _isAlive = true;
  _pool = std::unique_ptr<plz::ThreadPool>(new plz::ThreadPool(_maxThread));
  Logger::addLog("plz: Process [" + std::to_string(_pid) + "] start running.");
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_PROCESS_INFO, std::bind(&plz::Process::getInfo, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::ASSIGN_ORDER, std::bind(&plz::Process::addCommand, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_ORDER_STATE, std::bind(&plz::Process::sendData, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_PROCESS_END, std::bind(&plz::Process::getProcessEnd, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_FREE_SPACE, std::bind(&plz::Process::getFreeSpace, this, std::placeholders::_1)));
  while (true)
    {
      *_in >> data;
      if (functionPtr.find(data.getDataType()) != functionPtr.end())
	functionPtr[data.getDataType()](data);
      if (_pool->haveAvailableTask() == 0 && _pool->haveEndedTask() == 0 &&
	  _pool->getFreeThread() == _maxThread)
	{
	  if (_lastUpdate != 0 && _lastUpdate + 5 < time(0))
	    _isAlive = false;
	}
    }
  Logger::addLog("plz: Process [" + std::to_string(_pid) + "] exiting.");
}

void	plz::Process::getProcessEnd(PipeData const& pipeData)
{
  PipeData	res;

  if (pipeData.getDataType() == plz::PipeData::DataType::GET_PROCESS_END)
    {
      if (_isAlive)
	res.setInteger(0);
      else
	res.setInteger(1);
      *_out << res;
    }
}

void	plz::Process::getFreeSpace(PipeData const& pipeData)
{
  plz::PipeData	send;

  if (pipeData.getDataType() == plz::PipeData::DataType::GET_FREE_SPACE)
    {
      if (_isAlive)
	{
	  std::cout << "Max command : " << (2 * _maxThread) << std::endl;
	  std::cout << "Used thread : " << _maxThread - _pool->getFreeThread() << std::endl;
	  std::cout << "Task list : " << _pool->haveAvailableTask() << std::endl;
	  send.setInteger((2 * _maxThread) - ((_maxThread - _pool->getFreeThread()) + _pool->haveAvailableTask()));
	}
      else
	send.setInteger(-1);
      *_out << send;
    }
}

void	plz::Process::sendData(PipeData const& pipeData)
{
  PipeData	data(PipeData::DataType::SEND_DATA);
  PipeData	separator(PipeData::DataType::UNUSED);
  PipeData	result(PipeData::DataType::UNUSED);

  if (pipeData.getDataType() == PipeData::DataType::GET_ORDER_STATE &&
      _pool->haveEndedTask() > 0)
    {
      std::shared_ptr<plz::ThreadTask> ret = _pool->getAEndedTask();
      data.setInteger(ret->getResult().size());
      *_out << data;
      std::vector<std::string>::const_iterator	it;
      *_in >> result;
      it = ret->getResult().begin();
      while (it != ret->getResult().end())
      	{
      	  result.setString(*it);
      	  *_out << result;
      	  *_in >> result;
      	  ++it;
      	}
      *_out << separator;
      _lastUpdate = time(0);
    }
  else
    {
      PipeData	failure(PipeData::DataType::FAILURE);

      *_out << failure;
    }
}

void	plz::Process::addCommand(PipeData const& pipeData)
{
  PipeData	data(PipeData::DataType::UNUSED);
  PipeData	separator(PipeData::DataType::UNUSED);

  if (pipeData.getDataType() == PipeData::DataType::ASSIGN_ORDER)
    {
      *_out << separator;
      *_in >> data;
      std::cerr << "Add a command" << std::endl;
      std::shared_ptr<plz::ThreadTask>	ptr(new plz::ThreadTask(data.getData()._stockage.string, static_cast<Command::Information>(pipeData.getData()._stockage.integer)));

      _pool->insertNewTask(ptr);
      *_out << separator;
    }
}

pid_t	plz::Process::getPid() const
{
  return _pid;
}

void	plz::Process::getInfo(plz::PipeData const& pipeData)
{
  plz::PipeData	send;

  if (pipeData.getDataType() == plz::PipeData::DataType::GET_PROCESS_INFO)
    {
      if (_isAlive)
	send.setInteger(_pool->getFreeThread());
      else
	send.setInteger(-1);
      *_out << send;
    }
}

void	plz::Process::operator<<(plz::PipeData const& pipeData)
{
  *_in << pipeData;
}

void	plz::Process::operator>>(plz::PipeData& pipeData)
{
  *_out >> pipeData;
}

plz::Process::~Process()
{
  Logger::addLog("plz: Process [" + std::to_string(_pid) + "] Killed.");
  if (_pid > 0)
    kill(_pid, SIGQUIT);
}
