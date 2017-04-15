//
// Process.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:16 2017 Arnaud WURMEL
// Last update Sat Apr 15 21:40:01 2017 Arnaud WURMEL
//

#ifndef PROCESS_HH_
# define PROCESS_HH_

# include <queue>

namespace	Plazza
{
  class	Process : public Plazza::AProcess
  {
  public:
    Process(unsigned int);
    ~Process();

  public:
    void	runProcess();
    bool	createProcess();
    void	assignPipe(std::shared_ptr<APipe> const&);

  public:
    pid_t	getPid() const;

  public:
    virtual void	operator<<(PipeData<std::string> const&);
    virtual void	operator>>(PipeData<std::string>&);
    virtual void	operator<<(PipeData<int> const&);
    virtual void	operator>>(PipeData<int>&);

  private:
    bool	createThreads();
    void	getInfo(PipeData<int> const&);
    void	addCommand(PipeData<int> const&);

  private:
    unsigned int		_maxThread;
    pid_t			_pid;
    std::shared_ptr<APipe>	_pipe;
    std::queue<std::shared_ptr<Command>	>	_queue;
  };
}

#endif /* !PROCESS_HH_ */
