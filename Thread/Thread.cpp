//
// Thread.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:28:23 2017 Arnaud WURMEL
// Last update Fri Apr 28 22:36:50 2017 Arnaud WURMEL
//

#include <iostream>
#include <vector>
#include "Command.hh"
#include "Searcher.hh"
#include "Thread.hh"
#include "ThreadPool.hh"

plz::Thread::Thread(plz::ThreadPool& delegate) : _delegate(delegate)
{
  _state = plz::Thread::ThreadState::DIED;
  _thread = std::unique_ptr<std::thread>(new std::thread(&plz::Thread::threadLoop, this));
  _thread->detach();
}

void	plz::Thread::threadLoop()
{
  bool	success;
  std::shared_ptr<plz::ThreadTask>	ret;
  plz::Searcher	searcher;

  _state = plz::Thread::ThreadState::WAITING;
  while (1)
    {
      if (_delegate.haveAvailableTask() > 0)
      	{
      	  ret = _delegate.getATask(success);
      	  if (success)
	    {
	      _state = plz::Thread::ThreadState::WORKING;
	      ret->setResult(searcher.checkInformation(ret->getResearch(),
						       ret->getFilePath()));
	      _delegate.insertEndedTask(ret);
	      ret.reset();
	    }
      	}
      _state = plz::Thread::ThreadState::WAITING;
      if (_delegate.haveAvailableTask() == 0)
      	_delegate.waitForNewCommand();
    }
}

plz::Thread::ThreadState const&	plz::Thread::getState() const
{
  return _state;
}

plz::Thread::~Thread() {}
