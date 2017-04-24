//
// Process.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:16 2017 Arnaud WURMEL
// Last update Mon Apr 24 13:53:36 2017 Arnaud WURMEL
//

#ifndef PROCESS_HH_
# define PROCESS_HH_

# include <queue>
# include <thread>
# include <mutex>
# include "Thread.hh"
# include "ThreadPool.hh"

namespace	Plazza
{
  class	Process : public Plazza::AProcess
  {
  public:
    static unsigned int	processId;
  public:
    Process(unsigned int);
    ~Process();

  private:
    void	runProcess();

  public:
    pid_t	getPid() const;

  public:
    virtual void	operator<<(PipeData const&);
    virtual void	operator>>(PipeData&);

  private:
    void	threadLoop();
    bool	createThreads();

  private:
    void	getInfo(PipeData const&);
    void	addCommand(PipeData const&);
    void	sendData(PipeData const&);

  private:
    unsigned int		_maxThread;
    pid_t			_pid;
    std::shared_ptr<APipe>	_in;
    std::shared_ptr<APipe>	_out;
    std::unique_ptr<ThreadPool>	_pool;
  };
}

#endif /* !PROCESS_HH_ */
