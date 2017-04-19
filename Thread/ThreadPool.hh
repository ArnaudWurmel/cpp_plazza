//
// ThreadPool.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 17 19:21:44 2017 Arnaud WURMEL
// Last update Wed Apr 19 16:36:05 2017 Arnaud WURMEL
//

#ifndef THREADPOOL_HH_
# define THREADPOOL_HH_

# include <mutex>
# include <queue>
# include <condition_variable>
# include "ThreadTask.hh"

namespace	Plazza
{
  class	ThreadPool
  {
  public:
    ThreadPool(unsigned int);
    ~ThreadPool();

  public:
    unsigned int	getFreeThread() const;

  public:
    void	insertNewTask(std::shared_ptr<Plazza::ThreadTask> const&);
    std::shared_ptr<Plazza::ThreadTask>	getATask(bool&);
    void	insertEndedTask(std::shared_ptr<Plazza::ThreadTask> const&);

  public:
    bool	haveAvailableTask() const;
    void	waitForNewCommand();

  public:
    unsigned int	haveEndedTask() const;
    std::shared_ptr<Plazza::ThreadTask>	getAEndedTask();

  private:
    std::vector<std::unique_ptr<Plazza::Thread> >	_threadPool;
    std::queue<std::shared_ptr<Plazza::ThreadTask> >	_taskQueue;
    std::queue<std::shared_ptr<Plazza::ThreadTask> >	_endedTask;
    std::mutex						_queueLocker;
    std::condition_variable				_condVar;
  };
}

#endif /* !THREADPOOL_HH_ */
