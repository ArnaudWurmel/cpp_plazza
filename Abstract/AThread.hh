//
// AThread.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza/Abstract
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 09:19:29 2017 Arnaud WURMEL
// Last update Tue Apr 25 17:42:44 2017 baptiste
//

#ifndef ATHREAD_HH_
# define ATHREAD_HH_

namespace	plz
{
  class	AThread
  {
  public:
    enum	ThreadState
      {
	WORKING = 0,
	WAITING,
	DIE
      };

  public:
    virtual		~AThread() {}

  public:
    virtual bool	runThread() = 0;

  public:
    virtual ThreadState const&	getThreadState() const = 0;
  };
}

#endif /* !ATHREAD_HH_ */
