//
// Process.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:06 2017 Arnaud WURMEL
// Last update Wed Apr 19 18:21:42 2017 Arnaud WURMEL
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
#include "Thread.hh"
#include "ThreadTask.hh"
#include "ThreadPool.hh"
#include "Command.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "AProcess.hh"
#include "Process.hh"
#include "ThreadTask.hh"

Plazza::Process::Process(unsigned int maxThread)
{
  _pid = -1;
  _maxThread = maxThread;
}

bool	Plazza::Process::createProcess()
{
  _pid = fork();
  if (_pid == -1)
    {
      std::cout << "Plazza: Failed to add new process." << std::endl;
      return false;
    }
  if (_pid != 0)
    std::cout << "Plazza: Process [" << _pid << "] created." << std::endl;
  return true;
}
void	Plazza::Process::runProcess()
{
  PipeData	data;
  std::map<PipeData::DataType, std::function<void (PipeData const&)> > functionPtr;

  _pool = std::unique_ptr<Plazza::ThreadPool>(new Plazza::ThreadPool(_maxThread));
  std::cout << "Plazza: Process [" << _pid << "] start running." << std::endl;
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_PROCESS_INFO, std::bind(&Plazza::Process::getInfo, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::ASSIGN_ORDER, std::bind(&Plazza::Process::addCommand, this, std::placeholders::_1)));
  functionPtr.insert(std::make_pair(PipeData::DataType::GET_ORDER_STATE, std::bind(&Plazza::Process::sendData, this, std::placeholders::_1)));
  while (true)
    {
      (*_pipe) >> data;
      if (functionPtr.find(data.getDataType()) != functionPtr.end())
	functionPtr[data.getDataType()](data);
    }
  std::cout << "Plazza: Process [" << _pid << "] exiting." << std::endl;
}

void	Plazza::Process::sendData(PipeData const& pipeData)
{
  PipeData	data(PipeData::DataType::SEND_DATA);

  if (pipeData.getDataType() == PipeData::DataType::GET_ORDER_STATE &&
      _pool->haveEndedTask() > 0)
    {
      std::shared_ptr<Plazza::ThreadTask> ret = _pool->getAEndedTask();
      data.setInteger(ret->getResult().size());
      *_pipe << data;
    }
  else
    {
      PipeData	failure(PipeData::DataType::FAILURE);

      *_pipe << failure;
    }
}

void	Plazza::Process::addCommand(PipeData const& pipeData)
{
  PipeData	data(PipeData::DataType::UNUSED);
  PipeData	separator(PipeData::DataType::UNUSED);

  if (pipeData.getDataType() == PipeData::DataType::ASSIGN_ORDER)
    {
      *_pipe << separator;
      *_pipe >> data;
      std::shared_ptr<Plazza::ThreadTask>	ptr(new Plazza::ThreadTask(data.getData()._stockage.string));

      _pool->insertNewTask(ptr);
      *_pipe << separator;
    }
}

void	Plazza::Process::assignPipe(std::shared_ptr<Plazza::APipe> const& pipe)
{
  _pipe = pipe;
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
      send.setInteger(_pool->getFreeThread());
      *_pipe << send;
    }
}

void	Plazza::Process::operator<<(Plazza::PipeData const& pipeData)
{
  *_pipe << pipeData;
}

void	Plazza::Process::operator>>(Plazza::PipeData& pipeData)
{
  *_pipe >> pipeData;
}

Plazza::Process::~Process()
{
  std::cout << "Process[" << _pid << "] Killed." << std::endl;
  if (_pid > 0)
    kill(_pid, SIGQUIT);
}
