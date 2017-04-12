//
// Pipe.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:57:48 2017 Arnaud WURMEL
// Last update Wed Apr 12 20:11:52 2017 Arnaud WURMEL
//

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/select.h>
#include "Command.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "Pipe.hh"

Plazza::Pipe::Pipe(std::string const& pipeName)
{
  _pipeName = pipeName;
  _fd = -1;
}

bool	Plazza::Pipe::openPipe()
{
  if (mkfifo(_pipeName.c_str(), S_IWUSR | S_IRUSR) == -1)
    return false;
  if ((_fd = open(_pipeName.c_str(), O_RDWR)) == -1)
    {
      return false;
    }
  return true;
}

int	Plazza::Pipe::getFd() const
{
  return _fd;
}

void	Plazza::Pipe::operator<<(const PipeData& pipeData)
{
  write(_fd, &(pipeData.getData()), sizeof(pipeData.getData()));
}

void	Plazza::Pipe::operator>>(PipeData& pipeData)
{
  Plazza::PipeData::Data	data;

  read(_fd, &data, sizeof(data));
  pipeData.setString(data._str);
  pipeData.setDataType(data._type);
  pipeData.setInformation(data._inf);
}

Plazza::Pipe::~Pipe() {}
