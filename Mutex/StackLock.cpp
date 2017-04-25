//
// StackLock.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Apr 19 12:59:37 2017 Arnaud WURMEL
// Last update Tue Apr 25 17:43:28 2017 baptiste
//

#include "StackLock.hh"

plz::StackLock::StackLock(std::mutex& mutex) : _mutex(mutex)
{
  _mutex.lock();
}

plz::StackLock::~StackLock()
{
  _mutex.unlock();
}
