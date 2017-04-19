//
// Thread.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:28:23 2017 Arnaud WURMEL
// Last update Wed Apr 19 18:38:34 2017 Arnaud WURMEL
//

#include <iostream>
#include <vector>
#include "Command.hh"
#include "Searcher.hh"
#include "Thread.hh"
#include "ThreadPool.hh"

Plazza::Thread::Thread(Plazza::ThreadPool& delegate) : _delegate(delegate)
{
  _state = Plazza::Thread::ThreadState::DIED;
  _thread = std::unique_ptr<std::thread>(new std::thread(&Plazza::Thread::threadLoop, this));
}

void	Plazza::Thread::threadLoop()
{
  bool	success;
  std::shared_ptr<Plazza::ThreadTask>	ret;
  Plazza::Searcher	searcher;

  _state = Plazza::Thread::ThreadState::WAITING;
  while (1)
    {
      if (_delegate.haveAvailableTask() == true)
      	{
      	  ret = _delegate.getATask(success);
      	  if (success)
	    {
	      _state = Plazza::Thread::ThreadState::WORKING;
	      ret->setResult(searcher.checkInformation(Command::Information::PHONE_NUMBER,
						       ret->getFilePath()));
	      _delegate.insertEndedTask(ret);
	      ret.reset();
	    }
      	}
      _state = Plazza::Thread::ThreadState::WAITING;
      if (_delegate.haveAvailableTask() == false)
      	_delegate.waitForNewCommand();
    }
}

Plazza::Thread::ThreadState const&	Plazza::Thread::getState() const
{
  return _state;
}

Plazza::Thread::~Thread() {}