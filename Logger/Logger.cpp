//
// Logger.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Thu Apr 20 09:36:59 2017 Arnaud WURMEL
// Last update Thu Apr 20 09:51:54 2017 Arnaud WURMEL
//

#include "Logger.hh"

void	Plazza::Logger::addLog(std::string const& to_add)
{
  std::ofstream	file;

  file.open("plazza.log", std::ofstream::app);
  if (file.is_open())
    {
      file << to_add << std::endl;;
      file.close();
    }
}

void	Plazza::Logger::resetLogFile()
{
  std::ofstream	file;

  file.open("plazza.log", std::ofstream::trunc);
  if (file.is_open())
    {
      file.close();
    }
}
