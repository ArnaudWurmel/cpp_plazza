//
// Parser.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:56:28 2017 Arnaud WURMEL
// Last update Wed Apr 19 12:45:08 2017 Arnaud WURMEL
//

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <utility>
#include "Command.hh"
#include "Errors.hh"
#include "Parser.hh"

Plazza::Parser::Parser()
{
  _mapping.insert(std::make_pair("PHONE_NUMBER", Command::Information::PHONE_NUMBER));
  _mapping.insert(std::make_pair("EMAIL_ADDRESS", Command::Information::EMAIL_ADDRESS));
  _mapping.insert(std::make_pair("IP_ADDRESS", Command::Information::IP_ADDRESS));
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

std::shared_ptr<Plazza::Command>	Plazza::Parser::createToken(std::string& str) const
{
  std::shared_ptr<Plazza::Command> res = std::shared_ptr<Plazza::Command>(new Plazza::Command());
  std::vector<std::string>	token;
  size_t	pos;

  while ((pos = str.find(" ")) != std::string::npos)
    {
      token.push_back(str.substr(0, pos));
      str.erase(str.begin(), str.begin() + pos + 1);
    }
  if (str.size() > 0)
    token.push_back(str);
  if (token.size() >= 2 && _mapping.find(token[token.size() - 1]) != _mapping.end())
    {
      res->setCommandType((*_mapping.find(token[token.size() - 1])).second);
      token.pop_back();

      std::vector<std::string>::iterator	it = token.begin();
      while (it != token.end())
	{
	  res->addFilePath(*it);
	  ++it;
	}
    }
  else
    throw Error("Failed to parse line");
  return res;
}

std::vector<std::shared_ptr<Plazza::Command> >	Plazza::Parser::evalString(std::string& input) const
{
  std::vector<std::shared_ptr<Plazza::Command> >	res;
  std::string	curr;
  size_t	pos;

  while ((pos = input.find(";")) != std::string::npos)
    {
      curr = input.substr(0, pos);
      input.erase(input.begin(), input.begin() + pos + 1);
      epurStr(curr);
      if (curr.size() > 0)
	{
	  std::shared_ptr<Plazza::Command> cmd = createToken(curr);
	  if (cmd->getFilePaths().size() > 0)
	    res.push_back(cmd);
	}
    }
  if (input.size() > 0)
    {
      epurStr(input);
      std::shared_ptr<Plazza::Command> cmd = createToken(input);
      if (cmd->getFilePaths().size() > 0)
	res.push_back(cmd);
    }
  return res;
}

Plazza::Parser::~Parser() {}
