//
// ProcessError.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel@epitech.net>
// 
// Started on  Wed Apr 26 05:19:33 2017 Arnaud WURMEL
// Last update Wed Apr 26 06:52:07 2017 Arnaud WURMEL
//

#ifndef PROCESSERROR_HH_
# define PROCESSERROR_HH_

# include "Errors.hh"

namespace	plz
{
  class	ProcessError : public Error
  {
  public:
    ProcessError(std::string const&);
    ProcessError(const char *);
    ~ProcessError();
  };
}

#endif /* !PROCESSERROR_HH_ */
