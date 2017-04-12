//
// Process.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:16 2017 Arnaud WURMEL
// Last update Wed Apr 12 21:50:44 2017 Arnaud WURMEL
//

#ifndef PROCESS_HH_
# define PROCESS_HH_

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
    virtual void	operator<<(PipeData const&);
    virtual void	operator>>(PipeData&);

  private:
    bool	createThreads();
    void	getInfo(PipeData const&);

  private:
    unsigned int		_maxThread;
    pid_t			_pid;
    std::shared_ptr<APipe>	_pipe;
  };
}

#endif /* !PROCESS_HH_ */
