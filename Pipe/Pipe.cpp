//
// Pipe.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:57:48 2017 Arnaud WURMEL
// Last update Tue Apr 11 20:34:14 2017 Arnaud WURMEL
//

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include "Command.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "Pipe.hh"

Plazza::Pipe::Pipe(std::string const& pipeName)
{
  _pipeName = pipeName;
  _fd = -1;
}

Plazza::Pipe::~Pipe()
{

}

bool	Plazza::Pipe::openPipe()
{
  if (mkfifo(_pipeName.c_str(), O_RDWR) == -1)
    return false;
  if ((_fd = open(_pipeName.c_str(), O_RDWR)) == -1)
    return false;
  return true;
}

int	Plazza::Pipe::getFd() const
{
  return _fd;
}

void	Plazza::Pipe::operator<<(const PipeData* pipeData)
{

}

void	Plazza::Pipe::operator>>(PipeData& pipeData)
{

}
