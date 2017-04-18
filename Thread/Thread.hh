//
// Thread.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:26:42 2017 Arnaud WURMEL
// Last update Tue Apr 18 20:46:57 2017 Arnaud WURMEL
//

#ifndef THREAD_HH_
# define THREAD_HH_

# include <thread>
# include <vector>
# include <string>

namespace	Plazza
{
  class ThreadPool;
  class	Thread
  {
  public:
    enum	ThreadState
      {
	WORKING = 0,
	WAITING,
	DIED
      };
  public:
    Thread(Plazza::ThreadPool&);
    ~Thread();

  public:
    ThreadState const&	getState() const;

  private:
    void	threadLoop();

  private:
    std::unique_ptr<std::thread>	_thread;
    std::vector<std::string>		_result;
    ThreadState	_state;
    ThreadPool&	_delegate;
  };
}

#endif
