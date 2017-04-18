//
// ThreadPool.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:21:44 2017 Arnaud WURMEL
// Last update Mon Apr 17 19:36:48 2017 Arnaud WURMEL
//

#ifndef THREADPOOL_HH_
# define THREADPOOL_HH_

namespace	Plazza
{
  class	ThreadPool
  {
  public:
    ThreadPool(unsigned int);
    ~ThreadPool();

  public:
    unsigned int	getFreeThread() const;

  private:
    std::vector<std::unique_ptr<Plazza::Thread> >	_threadPool;
  };
}

#endif
