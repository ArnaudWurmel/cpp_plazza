//
// ThreadTask.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 18 20:04:24 2017 Arnaud WURMEL
// Last update Tue Apr 18 20:12:27 2017 Arnaud WURMEL
//

#include <vector>
#include <string>
#include "Command.hh"
#include "ThreadTask.hh"

Plazza::ThreadTask::ThreadTask(std::string const& file) : _file(file)
{
  _state = NotStarted;
}

Plazza::ThreadTask::TaskState const&	Plazza::ThreadTask::getTaskState() const
{
  return _state;
}

std::string const&	Plazza::ThreadTask::getFilePath() const
{
  return _file;
}

void	Plazza::ThreadTask::setTaskState(Plazza::ThreadTask::TaskState const& state)
{
  _state = state;
}

Plazza::ThreadTask::~ThreadTask() {}
