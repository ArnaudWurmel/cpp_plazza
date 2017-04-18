//
// ThreadPool.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:25:15 2017 Arnaud WURMEL
// Last update Mon Apr 17 19:41:48 2017 Arnaud WURMEL
//

#include <memory>
#include <vector>
#include "Thread.hh"
#include "ThreadPool.hh"

Plazza::ThreadPool::ThreadPool(unsigned int maxThread)
{
  unsigned int	i = 0;

  while (i < maxThread)
    {
      _threadPool.push_back(std::unique_ptr<Plazza::Thread>(new Plazza::Thread()));
      ++i;
    }
}

unsigned int	Plazza::ThreadPool::getFreeThread() const
{
  std::vector<std::unique_ptr<Plazza::Thread> >::const_iterator	it;
  unsigned int	freed;

  freed = 0;
  it = _threadPool.begin();
  while (it != _threadPool.end())
    {
      if ((*it)->getState() == Plazza::Thread::ThreadState::WAITING)
	++freed;
      ++it;
    }
  return freed;
}

Plazza::ThreadPool::~ThreadPool() {}
