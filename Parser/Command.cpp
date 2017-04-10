//
// Command.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:58:22 2017 Arnaud WURMEL
// Last update Mon Apr 10 20:07:53 2017 Arnaud WURMEL
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

Plazza::Command::~Command() {}
