//
// Pipe.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:57:48 2017 Arnaud WURMEL
// Last update Wed Apr 12 23:24:18 2017 Arnaud WURMEL
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

void	Plazza::Pipe::operator<<(const PipeData& pipeData)
{
  std::ofstream	file(_pipeName);
  PipeData::Data	data;

  if (file)
    {
      data._type = pipeData.getDataType();
      data._inf = pipeData.getInformation();
      data._curr_thread = pipeData.getCurrThread();
      pipeData.getString().copy(data._str, MAX_DATA);
      std::cout << "String sended : " << data._str << std::endl;
      file << (reinterpret_cast<char *>(&data));
      file.close();
    }
}

void	Plazza::Pipe::operator>>(PipeData& pipeData)
{
  std::ifstream	file(_pipeName);
  PipeData::Data	data;

  if (file)
    {
      memset(&data, 0, sizeof(data));
      file.read(reinterpret_cast<char *>(&data), sizeof(data));      
      file.close();
      std::cout << "String : " << data._str << std::endl;
      pipeData.setString(data._str);
      pipeData.setDataType(data._type);
      pipeData.setInformation(data._inf);
    }
}

Plazza::Pipe::~Pipe()
{
  unlink(_pipeName.c_str());
}
