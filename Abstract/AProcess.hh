//
// AProcess.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 14:17:33 2017 Arnaud WURMEL
// Last update Mon Apr 24 13:29:53 2017 Arnaud WURMEL
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
    virtual pid_t	getPid() const = 0;

  public:
    virtual void	operator<<(const PipeData&) = 0;
    virtual void	operator>>(PipeData&) = 0;
  };
}

#endif /* !APROCESS_HH_ */
