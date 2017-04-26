//
// ThreadPool.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:25:15 2017 Arnaud WURMEL
// Last update Wed Apr 26 02:10:33 2017 Arnaud WURMEL
//

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "Command.hh"
#include "ThreadTask.hh"
#include "Thread.hh"
#include "ThreadPool.hh"

plz::ThreadPool::ThreadPool(unsigned int maxThread)
{
  unsigned int	i = 0;

  while (i < maxThread)
    {
      _threadPool.push_back(std::unique_ptr<plz::Thread>(new plz::Thread(*this)));
      ++i;
    }
}

unsigned int	plz::ThreadPool::getFreeThread() const
{
  std::vector<std::unique_ptr<plz::Thread> >::const_iterator	it;
  unsigned int	freed;

  freed = 0;
  it = _threadPool.begin();
  while (it != _threadPool.end())
    {
      if ((*it)->getState() == plz::Thread::ThreadState::WAITING)
	++freed;
      ++it;
    }
  return freed;
}

std::shared_ptr<plz::ThreadTask>	plz::ThreadPool::getATask(bool& success)
{
  std::shared_ptr<plz::ThreadTask>	ret;

  success = false;
  if (_queueLocker.try_lock())
    {
      if (_taskQueue.size() > 0)
	{
	  success = true;
	  ret = _taskQueue.front();
	  _taskQueue.pop();
	}
      _queueLocker.unlock();
    }
  return ret;
}

void	plz::ThreadPool::insertEndedTask(std::shared_ptr<plz::ThreadTask> const& task)
{
  _queueLocker.lock();
  _endedTask.push(task);
  _queueLocker.unlock();
}

void	plz::ThreadPool::insertNewTask(std::shared_ptr<plz::ThreadTask> const& task)
{
  _queueLocker.lock();
  _taskQueue.push(task);
  _queueLocker.unlock();
  _condVar.notify_one();
}

unsigned int	plz::ThreadPool::haveAvailableTask() const
{
  return _taskQueue.size();
}

unsigned int	plz::ThreadPool::haveEndedTask() const
{
  return _endedTask.size();
}

std::shared_ptr<plz::ThreadTask>	plz::ThreadPool::getAEndedTask()
{
  std::shared_ptr<plz::ThreadTask>	ret;

  _queueLocker.lock();
  ret = _endedTask.front();
  _endedTask.pop();
  _queueLocker.unlock();
  return ret;
}

void	plz::ThreadPool::waitForNewCommand()
{
  std::unique_lock<std::mutex>	lock(this->_queueLocker);

  _condVar.wait(lock);
}

plz::ThreadPool::~ThreadPool() {}
