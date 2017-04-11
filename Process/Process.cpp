//
// Process.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:06 2017 Arnaud WURMEL
// Last update Tue Apr 11 15:43:36 2017 Arnaud WURMEL
//

#include <unistd.h>
#include "AProcess.hh"
#include "Process.hh"

Plazza::Process::Process(unsigned int maxThread)
{
  _pid = -1;
  _maxThread = maxThread;
}

bool	Plazza::Process::createProcess()
{
  return false;
}

void	Plazza::Process::runProcess()
{

}

bool	Plazza::Process::createThreads()
{
  return false;
}

pid_t	Plazza::Process::getPid() const
{
  return _pid;
}

Plazza::Process::~Process() {}
