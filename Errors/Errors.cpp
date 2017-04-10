//
// Errors.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza/Errors
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:28:13 2017 Arnaud WURMEL
// Last update Mon Apr 10 10:39:53 2017 Arnaud WURMEL
//

#include "Errors.hh"

Plazza::Error::Error(std::string const& what)
{
  _what = what;
}

Plazza::Error::Error(const char *what)
{
  _what = std::string(what);
}

const char *Plazza::Error::what() const throw()
{
  return _what.c_str();
}

Plazza::Error::~Error() {}
