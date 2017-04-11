//
// Process.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:16 2017 Arnaud WURMEL
// Last update Tue Apr 11 15:40:31 2017 Arnaud WURMEL
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

  public:
    pid_t	getPid() const;

  private:
    bool	createThreads();

  private:
    unsigned int	_maxThread;
    pid_t		_pid;
  };
}

#endif /* !PROCESS_HH_ */
