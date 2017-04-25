//
// Errors.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza/Errors
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:28:13 2017 Arnaud WURMEL
// Last update Tue Apr 25 17:59:25 2017 baptiste
//

#include "Errors.hh"

plz::Error::Error(std::string const& what)
{
  _what = what;
}

plz::Error::Error(const char *what)
{
  _what = std::string(what);
}

const char *plz::Error::what() const throw()
{
  return _what.c_str();
}

plz::Error::~Error() {}
