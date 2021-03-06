//
// APipe.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:53:28 2017 Arnaud WURMEL
// Last update Tue Apr 25 17:42:15 2017 baptiste
//

#ifndef APIPE_HH_
# define APIPE_HH_

namespace	plz
{
  class	APipe
  {
  public:
    virtual ~APipe() {}

  public:
    virtual bool	openPipe() = 0;

  public:
    virtual void	operator<<(const PipeData&) = 0;
    virtual void	operator>>(PipeData&) = 0;
  };
}

#endif /* !APIPE_HH_ */
