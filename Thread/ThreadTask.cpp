//
// ThreadTask.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 18 20:04:24 2017 Arnaud WURMEL
// Last update Wed Apr 19 20:48:08 2017 Arnaud WURMEL
//

#include <vector>
#include <string>
#include "Command.hh"
#include "ThreadTask.hh"

Plazza::ThreadTask::ThreadTask(std::string const& file, Command::Information const& research) : _file(file), _research(research)
{
  _state = NotStarted;
}

Plazza::ThreadTask::TaskState const&	Plazza::ThreadTask::getTaskState() const
{
  return _state;
}

Plazza::Command::Information const&	Plazza::ThreadTask::getResearch() const
{
  return _research;
}

std::string const&	Plazza::ThreadTask::getFilePath() const
{
  return _file;
}

std::vector<std::string> const&	Plazza::ThreadTask::getResult() const
{
  return _result;
}

void	Plazza::ThreadTask::setTaskState(Plazza::ThreadTask::TaskState const& state)
{
  _state = state;
}

void	Plazza::ThreadTask::setResult(std::vector<std::string> const& result)
{
  _result = result;
}

Plazza::ThreadTask::~ThreadTask() {}
