//
// Errors.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza/Errors
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:23:37 2017 Arnaud WURMEL
// Last update Tue Apr 25 17:59:40 2017 baptiste
//

#ifndef ERRORS_HH_
# define ERRORS_HH_

# include <string>
# include <exception>

namespace	plz
{
  class	Error : public std::exception
  {
  public:
    Error(std::string const&);
    Error(const char *);
    ~Error();

  public:
    virtual const char	*what() const throw();

  protected:
    std::string	_what;
  };
}

#endif /* !ERRORS_HH_ */
