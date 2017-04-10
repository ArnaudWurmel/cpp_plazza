//
// Parser.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:56:28 2017 Arnaud WURMEL
// Last update Mon Apr 10 20:34:37 2017 Arnaud WURMEL
//

#include <iostream>
#include <memory>
#include <vector>
#include "Command.hh"
#include "Parser.hh"

Plazza::Parser::Parser()
{

}

bool	Plazza::Parser::isCharacterAfter(std::string::iterator it, std::string::iterator const& end) const
{
  while (it != end)
    {
      if (*it != ' ' && *it != '\t')
	return true;
      ++it;
    }
  return false;
}

void		Plazza::Parser::epurStr(std::string& str) const
{
  std::string::iterator	it;
  bool			one_space;

  one_space = false;
  it = str.begin();
  while (it != str.end() && (*it == ' ' || *it == '\t'))
    str.erase(it);
  while (it != str.end())
    {
      if ((*it == ' ' || *it == '\t') && one_space == false && isCharacterAfter(it, str.end()))
	{
	  if (*it == '\t')
	    *it = ' ';
	  ++it;
	  one_space = true;
	}
      else if (*it != ' ' && *it != '\t')
	{
	  ++it;
	  one_space = false;
	}
      else
	str.erase(it);
    }
}

std::vector<std::unique_ptr<Plazza::Command> >	Plazza::Parser::evalString(std::string& input) const
{
  std::vector<std::unique_ptr<Plazza::Command> >	res;
  std::string	curr;
  size_t	pos;

  while ((pos = input.find(";")) != std::string::npos)
    {
      curr = input.substr(0, pos);
      input.erase(input.begin(), input.begin() + pos + 1);
      epurStr(curr);
    }
  epurStr(curr);
  return res;
}

Plazza::Parser::~Parser() {}
