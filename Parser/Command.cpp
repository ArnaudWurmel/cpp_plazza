//
// Command.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:58:22 2017 Arnaud WURMEL
// Last update Tue Apr 25 18:01:28 2017 baptiste
//

#include <iostream>
#include <string>
#include <vector>
#include "Command.hh"

plz::Command::Command()
{
  _commandType = plz::Command::Information::PHONE_NUMBER;
}

void	plz::Command::addFilePath(const std::string& newFile)
{
  _filepaths.push_back(newFile);
}

std::vector<std::string> const&	plz::Command::getFilePaths() const
{
  return _filepaths;
}

void	plz::Command::setCommandType(const plz::Command::Information& commandType)
{
  _commandType = commandType;
}

const plz::Command::Information&	plz::Command::getCommandType() const
{
  return _commandType;
}

std::ostream&	operator<<(std::ostream& os, const plz::Command& cmd)
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

plz::Command::~Command() {}
