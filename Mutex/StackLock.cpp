//
// StackLock.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Apr 19 12:59:37 2017 Arnaud WURMEL
// Last update Wed Apr 19 13:00:54 2017 Arnaud WURMEL
//

#include "StackLock.hh"

Plazza::StackLock::StackLock(std::mutex& mutex) : _mutex(mutex)
{
  _mutex.lock();
}

Plazza::StackLock::~StackLock()
{
  _mutex.unlock();
}
