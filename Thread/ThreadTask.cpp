//
// ThreadTask.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 18 20:04:24 2017 Arnaud WURMEL
// Last update Tue Apr 25 17:56:02 2017 baptiste
//

#include <vector>
#include <string>
#include "Command.hh"
#include "ThreadTask.hh"

plz::ThreadTask::ThreadTask(std::string const& file, Command::Information const& research) : _file(file), _research(research)
{
  _state = NotStarted;
}

plz::ThreadTask::TaskState const&	plz::ThreadTask::getTaskState() const
{
  return _state;
}

plz::Command::Information const&	plz::ThreadTask::getResearch() const
{
  return _research;
}

std::string const&	plz::ThreadTask::getFilePath() const
{
  return _file;
}

std::vector<std::string> const&	plz::ThreadTask::getResult() const
{
  return _result;
}

void	plz::ThreadTask::setTaskState(plz::ThreadTask::TaskState const& state)
{
  _state = state;
}

void	plz::ThreadTask::setResult(std::vector<std::string> const& result)
{
  _result = result;
}

plz::ThreadTask::~ThreadTask() {}
