//
// Thread.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 09:21:15 2017 Arnaud WURMEL
// Last update Tue Apr 11 09:30:44 2017 Arnaud WURMEL
//

#ifndef THREAD_HH_
# define THREAD_HH_

namespace	Plazza
{
  class	Thread : public Plazza::AThread
  {
  public:
    Thread();
    ~Thread();

  public:
    bool	runThread();

  public:
    AThread::ThreadState const&	getThreadState() const;

  private:
    AThread::ThreadState	_state;
  };
}

#endif /* !THREAD_HH_ */
