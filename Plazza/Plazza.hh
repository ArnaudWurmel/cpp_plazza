//
// Plazza.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:20:05 2017 Arnaud WURMEL
// Last update Mon Apr 24 16:10:08 2017 Arnaud WURMEL
//

#ifndef PLAZZA_HH_
# define PLAZZA_HH_

# include <mutex>
# include <thread>

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
    void	threadGetData();

  private:
    void	dispatchCommand(const std::vector<std::shared_ptr<Command> >&);
    void	assignCommand(std::string const&, Command::Information const&,
			      std::shared_ptr<AProcess>&);
    bool	createNewProcess();

  private:
    unsigned int	_maxThreads;
    std::vector<std::shared_ptr<AProcess> >	_process;
    std::unique_ptr<std::thread>		_threadData;
    std::mutex		_writer;
  };
}

#endif /* !PLAZZA_HH_ */
