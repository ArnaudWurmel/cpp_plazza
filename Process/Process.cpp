//
// Process.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:06 2017 Arnaud WURMEL
// Last update Sat Apr 15 21:49:35 2017 Arnaud WURMEL
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
#include "Command.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "AProcess.hh"
#include "Process.hh"

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
  PipeData<int>	data;
  std::map<PipeData<int>::DataType, std::function<void (PipeData<int> const&)> >	functionPtr;

  std::cout << "Plazza: Process [" << _pid << "] start running." << std::endl;
  functionPtr.insert(std::make_pair(PipeData<int>::DataType::GET_PROCESS_INFO, std::bind(&Plazza::Process::getInfo, this, std::placeholders::_1)));
  while (true)
    {
      (*_pipe) >> data;
      if (functionPtr.find(data.getDataType()) != functionPtr.end())
      	functionPtr[data.getDataType()](data);
    std::cout << "Plazza: Process [" << _pid << "] received data." << std::endl;
    }
  std::cout << "Plazza: Process [" << _pid << "] exiting." << std::endl;
}

void	Plazza::Process::assignPipe(std::shared_ptr<Plazza::APipe> const& pipe)
{
  _pipe = pipe;
}

bool	Plazza::Process::createThreads()
{
  return false;
}

pid_t	Plazza::Process::getPid() const
{
  return _pid;
}

void	Plazza::Process::getInfo(Plazza::PipeData<int> const& pipeData)
{
  Plazza::PipeData<int>	send;

  *_pipe << send;
}

void	Plazza::Process::operator<<(Plazza::PipeData<std::string> const& pipeData)
{
  *_pipe << pipeData;
}

void	Plazza::Process::operator>>(Plazza::PipeData<std::string>& pipeData)
{
  *_pipe >> pipeData;
}

void	Plazza::Process::operator<<(Plazza::PipeData<int> const& pipeData)
{
  *_pipe << pipeData;
}

void	Plazza::Process::operator>>(Plazza::PipeData<int>& pipeData)
{
  *_pipe >> pipeData;
}

Plazza::Process::~Process()
{
  std::cout << "Process[" << _pid << "] Killed." << std::endl;
  if (_pid > 0)
    kill(_pid, SIGQUIT);
}
