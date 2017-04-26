//
// ProcessError.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel@epitech.net>
// 
// Started on  Wed Apr 26 05:19:49 2017 Arnaud WURMEL
// Last update Wed Apr 26 06:52:30 2017 Arnaud WURMEL
//

#include "ProcessError.hh"

plz::ProcessError::ProcessError(std::string const& what) : Error(what)
{
  _what = what;
}

plz::ProcessError::ProcessError(const char *what) : Error(what)
{
  _what = std::string(what);
}

plz::ProcessError::~ProcessError() {}
