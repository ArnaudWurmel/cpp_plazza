//
// Process.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:06 2017 Arnaud WURMEL
// Last update Tue Apr 25 11:48:20 2017 Arnaud WURMEL
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

unsigned int	Plazza::Process::processId = 0;

Plazza::Process::Process(unsigned int maxThread)
{
  _pid = -1;
  _maxThread = maxThread;
  _lastUpdate = 0;
  std::string	pipePath = "/tmp/" + std::to_string(Plazza::Process::processId);
  _in = std::shared_ptr<APipe>(new Pipe(pipePath + ".in.fifo"));
  _in->openPipe();
  _out = std::shared_ptr<APipe>(new Pipe(pipePath + ".out.fifo"));
  _out->openPipe();
  Plazza::Process::processId += 1;
  _pid = fork();
  if (_pid == -1)
    {
      std::cerr << "Plazza: Failed to add new process." << std::endl;
      throw Error("Failed to add process");
    }
  if (_pid != 0)
    Logger::addLog("Plazza: Process [" + std::to_string(_pid) + "] created.");
  else
    {
      runProcess();
      exit(0);
    }
}

void	Plazza::Process::runProcess()
{
  PipeData	data;
  std::map<PipeData::DataType, std::function<void (PipeData const&)> > functionPtr;

  _isAlive = true;
  _pool = std::unique_ptr<Plazza::ThreadPool>(new Plazza::ThreadPool(_maxThread));
  Logger::addLog("Plazza: Process [" + std::to_string(_pid) + "] start running.");
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_PROCESS_INFO, std::bind(&Plazza::Process::getInfo, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::ASSIGN_ORDER, std::bind(&Plazza::Process::addCommand, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_ORDER_STATE, std::bind(&Plazza::Process::sendData, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_PROCESS_END, std::bind(&Plazza::Process::getProcessEnd, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_FREE_SPACE, std::bind(&Plazza::Process::getFreeSpace, this, std::placeholders::_1)));
  while (true)
    {
      *_in >> data;
      if (functionPtr.find(data.getDataType()) != functionPtr.end())
	functionPtr[data.getDataType()](data);
      if (_pool->haveAvailableTask() == 0 && _pool->haveEndedTask() == 0)
	{
	  if (_lastUpdate != 0 && _lastUpdate + 5 < time(0))
	    _isAlive = false;
	}
    }
  Logger::addLog("Plazza: Process [" + std::to_string(_pid) + "] exiting.");
}

void	Plazza::Process::getProcessEnd(PipeData const& pipeData)
{
  PipeData	res;

  if (pipeData.getDataType() == Plazza::PipeData::DataType::GET_PROCESS_END)
    {
      if (_isAlive)
	res.setInteger(0);
      else
	res.setInteger(1);
      *_out << res;
    }
}

void	Plazza::Process::getFreeSpace(PipeData const& pipeData)
{
  Plazza::PipeData	send;

  if (pipeData.getDataType() == Plazza::PipeData::DataType::GET_FREE_SPACE)
    {
      if (_isAlive)
	send.setInteger((2 * _maxThread) - ((_maxThread - _pool->getFreeThread()) + _pool->haveAvailableTask()));
      else
	send.setInteger(-1);
      *_out << send;
    }
}

void	Plazza::Process::sendData(PipeData const& pipeData)
{
  PipeData	data(PipeData::DataType::SEND_DATA);
  PipeData	separator(PipeData::DataType::UNUSED);
  PipeData	result(PipeData::DataType::UNUSED);

  if (pipeData.getDataType() == PipeData::DataType::GET_ORDER_STATE &&
      _pool->haveEndedTask() > 0)
    {
      std::shared_ptr<Plazza::ThreadTask> ret = _pool->getAEndedTask();
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

void	Plazza::Process::addCommand(PipeData const& pipeData)
{
  PipeData	data(PipeData::DataType::UNUSED);
  PipeData	separator(PipeData::DataType::UNUSED);

  if (pipeData.getDataType() == PipeData::DataType::ASSIGN_ORDER)
    {
      *_out << separator;
      *_in >> data;
      std::shared_ptr<Plazza::ThreadTask>	ptr(new Plazza::ThreadTask(data.getData()._stockage.string, static_cast<Command::Information>(pipeData.getData()._stockage.integer)));

      _pool->insertNewTask(ptr);
      *_out << separator;
    }
}

pid_t	Plazza::Process::getPid() const
{
  return _pid;
}

void	Plazza::Process::getInfo(Plazza::PipeData const& pipeData)
{
  Plazza::PipeData	send;

  if (pipeData.getDataType() == Plazza::PipeData::DataType::GET_PROCESS_INFO)
    {
      if (_isAlive)
	send.setInteger(_pool->getFreeThread());
      else
	send.setInteger(-1);
      *_out << send;
    }
}

void	Plazza::Process::operator<<(Plazza::PipeData const& pipeData)
{
  *_in << pipeData;
}

void	Plazza::Process::operator>>(Plazza::PipeData& pipeData)
{
  *_out >> pipeData;
}

Plazza::Process::~Process()
{
  Logger::addLog("Plazza: Process [" + std::to_string(_pid) + "] Killed.");
  if (_pid > 0)
    kill(_pid, SIGQUIT);
}
