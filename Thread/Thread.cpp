//
// Thread.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 09:22:30 2017 Arnaud WURMEL
// Last update Tue Apr 11 09:31:06 2017 Arnaud WURMEL
//

#include "AThread.hh"
#include "Thread.hh"

Plazza::Thread::Thread()
{
  _state = Plazza::AThread::DIE;
}

bool	Plazza::Thread::runThread()
{
  return false;
}

Plazza::Thread::ThreadState const&	Plazza::Thread::getThreadState() const
{
  return _state;
}

Plazza::Thread::~Thread() {}
