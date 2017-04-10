//
// Command.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:58:22 2017 Arnaud WURMEL
// Last update Mon Apr 10 21:17:28 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include <vector>
#include "Command.hh"

Plazza::Command::Command()
{
  _commandType = Plazza::Command::Information::PHONE_NUMBER;
}

void	Plazza::Command::addFilePath(const std::string& newFile)
{
  _filepaths.push_back(newFile);
}

std::vector<std::string> const&	Plazza::Command::getFilePaths() const
{
  return _filepaths;
}

void	Plazza::Command::setCommandType(const Plazza::Command::Information& commandType)
{
  _commandType = commandType;
}

const Plazza::Command::Information&	Plazza::Command::getCommandType() const
{
  return _commandType;
}

std::ostream&	operator<<(std::ostream& os, const Plazza::Command& cmd)
{
  os << "Command type : " << cmd.getCommandType() << "| Filepaths: " << std::endl;
  std::vector<std::string>	filepaths = cmd.getFilePaths();
  std::vector<std::string>::const_iterator	it;

  it = filepaths.begin();
  while (it != filepaths.end())
    {
      os << *it << std::endl;
      ++it;
    }
  os << "======= End command ======";
  return os;
}

Plazza::Command::~Command() {}
