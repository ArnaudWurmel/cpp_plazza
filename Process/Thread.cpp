//
// Thread.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:28:23 2017 Arnaud WURMEL
// Last update Mon Apr 17 19:41:17 2017 Arnaud WURMEL
//

#include "Thread.hh"

Plazza::Thread::Thread()
{
  _state = Plazza::Thread::ThreadState::DIED;
  _thread = std::unique_ptr<std::thread>(new std::thread(&Plazza::Thread::threadLoop, this));
}

void	Plazza::Thread::threadLoop()
{
  _state = Plazza::Thread::ThreadState::WAITING;
  while (1)
    {

    }
}

Plazza::Thread::ThreadState const&	Plazza::Thread::getState() const
{
  return _state;
}

Plazza::Thread::~Thread() {}
