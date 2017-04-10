//
// Process.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:51:16 2017 Arnaud WURMEL
// Last update Mon Apr 10 19:54:44 2017 Arnaud WURMEL
//

#ifndef PROCESS_HH_
# define PROCESS_HH_

namespace	Plazza
{
  class	Process
  {
  public:
    Process(unsigned int);
    ~Process();

  public:
    void	processLoop();

  private:
    unsigned int	_maxThread;
  };
}

#endif /* !PROCESS_HH_ */
