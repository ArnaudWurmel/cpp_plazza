//
// Pipe.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:57:48 2017 Arnaud WURMEL
// Last update Mon Apr 24 13:51:29 2017 Arnaud WURMEL
//

#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <errno.h>
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
}

bool	Plazza::Pipe::openPipe()
{
  if (mkfifo(_pipeName.c_str(), S_IWUSR | S_IRUSR) == -1)
    return false;
  if ((_fd = open(_pipeName.c_str(), O_RDWR)) == -1)
    return false;
  return true;
}

void	Plazza::Pipe::operator<<(const PipeData& pipeData)
{
  PipeData::Data	data;

  if (_fd != -1)
    {
      memset(&data, 0, sizeof(data));
      data._stockage = pipeData.getData()._stockage;
      data._type = pipeData.getDataType();
      write(_fd, &data, sizeof(data));
    }
}

void	Plazza::Pipe::operator>>(PipeData& pipeData)
{
  PipeData::Data	data;

  if (_fd != -1)
    {
      memset(&data, 0, sizeof(data));
      read(_fd, &data, sizeof(data));
      pipeData.setStockage(data._stockage);
      pipeData.setDataType(data._type);
    }
}

Plazza::Pipe::~Pipe()
{
  close(_fd);
  unlink(_pipeName.c_str());
}
