//
// AProcess.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 14:17:33 2017 Arnaud WURMEL
// Last update Tue Apr 18 10:34:36 2017 Arnaud WURMEL
//

#ifndef APROCESS_HH_
# define APROCESS_HH_

namespace	Plazza
{
  class	AProcess
  {
  public:
    enum	AutoOrder
      {
	GET_INFO = 0
      };
  public:
    virtual ~AProcess() {}

  public:
    virtual void	runProcess() = 0;
    virtual bool	createProcess() = 0;
    virtual void	assignPipe(std::shared_ptr<APipe> const&) = 0;

  public:
    virtual pid_t	getPid() const = 0;

  public:
    virtual void	operator<<(const PipeData&) = 0;
    virtual void	operator>>(PipeData&) = 0;
  };
}

#endif /* !APROCESS_HH_ */
