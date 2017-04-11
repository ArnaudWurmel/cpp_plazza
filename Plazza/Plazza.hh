//
// Plazza.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:20:05 2017 Arnaud WURMEL
// Last update Tue Apr 11 16:15:16 2017 Arnaud WURMEL
//

#ifndef PLAZZA_HH_
# define PLAZZA_HH_

namespace	Plazza
{
  class	Plazza
  {
  public:
    Plazza(unsigned int);
    ~Plazza();

  public:
    void	mainLoop();

  private:
    void	dispatchCommand(const std::vector<std::shared_ptr<Command> >&);

  private:
    unsigned int	_maxThreads;
    std::vector<std::shared_ptr<AProcess> >	_process;
  };
}

#endif /* !PLAZZA_HH_ */
