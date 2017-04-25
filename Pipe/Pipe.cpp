//
// Pipe.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:57:48 2017 Arnaud WURMEL
// Last update Tue Apr 25 13:26:31 2017 Arnaud WURMEL
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
#include <sys/time.h>
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
  int	result;
  PipeData::Data	data;
  fd_set		readset;
  struct timeval	tv;

  if (_fd != -1)
    {
      tv.tv_sec = 1;
      tv.tv_usec = 0;
      FD_ZERO(&readset);
      FD_SET(_fd, &readset);
      memset(&data, 0, sizeof(data));
      result = select(_fd + 1, &readset, NULL, NULL, &tv);
      if (result > 0)
	{
	  read(_fd, &data, sizeof(data));
	  pipeData.setStockage(data._stockage);
	  pipeData.setDataType(data._type);
	}
      else
	{
	  std::cout << result << std::endl;
	  pipeData.setInteger(-1);
	}
    }
}

Plazza::Pipe::~Pipe()
{
  close(_fd);
  unlink(_pipeName.c_str());
}
