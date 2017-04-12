//
// Process.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:06 2017 Arnaud WURMEL
// Last update Wed Apr 12 17:39:02 2017 Arnaud WURMEL
//

#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <memory>
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
  PipeData	data;

  std::cout << "Plazza: Process [" << _pid << "] start running." << std::endl;
  while (true)
    {
      *_pipe >> data;
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

Plazza::Process::~Process()
{
  exit(0);
}
