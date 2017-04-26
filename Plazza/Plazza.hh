//
// Plazza.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:20:05 2017 Arnaud WURMEL
// Last update Wed Apr 26 04:20:37 2017 Arnaud WURMEL
//

#ifndef PLAZZA_HH_
# define PLAZZA_HH_

# include <mutex>
# include <thread>
# include "UIManager.hh"

namespace	plz
{
  class	Plazza
  {
  public:
    Plazza(unsigned int);
    ~Plazza();

  public:
    void	mainLoop();

  private:
    void	threadGetData();

  private:
    void	dispatchCommand(const std::vector<std::shared_ptr<Command> >&);
    void	assignCommand(std::string const&, Command::Information const&,
			      std::shared_ptr<AProcess>&);
    bool	createNewProcess();
    bool	checkExitProcess(std::vector<std::shared_ptr<AProcess> >::iterator&);

  private:
    unsigned int	_maxThreads;
    std::vector<std::shared_ptr<AProcess> >	_process;
    std::unique_ptr<std::thread>		_threadData;
    std::mutex		_writer;
    plz::UIManager	*_manager;
  };
}

#endif /* !PLAZZA_HH_ */
