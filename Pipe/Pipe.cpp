//
// Pipe.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:57:48 2017 Arnaud WURMEL
// Last update Sat Apr 15 22:18:00 2017 Arnaud WURMEL
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
  return true;
}

void	Plazza::Pipe::operator<<(const PipeData<int>& pipeData)
{
  std::ofstream	file(_pipeName);
  PipeData<int>::Data	data;

  if (file)
    {
      memset(&data, 0, sizeof(data));
      data._stockage = pipeData.getStockage();
      data._type = pipeData.getDataType();
      file.write(reinterpret_cast<char *>(&data), sizeof(data));
      file.close();
    }
}

void	Plazza::Pipe::operator>>(PipeData<int>& pipeData)
{
  std::ifstream	file(_pipeName);
  PipeData<int>::Data	data;

  if (file)
    {
      memset(&data, 0, sizeof(data));
      file.read(reinterpret_cast<char *>(&data), sizeof(data));      
      file.close();
      pipeData.setStockage(data._stockage);
      pipeData.setDataType(data._type);
    }
}

void	Plazza::Pipe::operator<<(const PipeData<std::string>& pipeData)
{
  std::ofstream	file(_pipeName);
  PipeData<std::string>::Data	data;

  if (file)
    {
      memset(&data, 0, sizeof(data));
      data._stockage = pipeData.getStockage();
      data._type = pipeData.getDataType();
      file.write(reinterpret_cast<char *>(&data), sizeof(data));
      file.close();
    }
}

void	Plazza::Pipe::operator>>(PipeData<std::string>& pipeData)
{
  std::ifstream	file(_pipeName);
  PipeData<std::string>::Data	data;

  if (file)
    {
      memset(&data, 0, sizeof(data));
      file.read(reinterpret_cast<char *>(&data), sizeof(data));      
      file.close();
      pipeData.setStockage(data._stockage);
      pipeData.setDataType(data._type);
    }
}

Plazza::Pipe::~Pipe()
{
  unlink(_pipeName.c_str());
}
