//
// Logger.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Thu Apr 20 09:36:59 2017 Arnaud WURMEL
// Last update Fri Apr 28 23:45:59 2017 Arnaud WURMEL
//

#include <cstdio>
#include "Logger.hh"

void	plz::Logger::addLog(std::string const& to_add)
{
  std::ofstream	file;

  file.open("plazza.log", std::ofstream::app);
  if (file.is_open())
    {
      file << to_add << std::endl;;
      file.close();
    }
}

void	plz::Logger::addResult(std::string const& to_add)
{
  std::ofstream	file;

  file.open("plazza.result", std::ofstream::app);
  if (file.is_open())
    {
      file << to_add << std::endl;;
      file.close();
    }
}

void	plz::Logger::endResult()
{
  std::ofstream	file;

  file.open("plazza.result", std::ofstream::app);
  if (file.is_open())
    {
      file << std::endl;
      file.close();
    }
}

void	plz::Logger::resetLogFile()
{
  std::ofstream	file;

  std::remove("plazza.log");
  std::remove("plazza.result");
  file.open("plazza.log", std::ofstream::trunc);
  if (file.is_open())
    {
      file.close();
    }
  file.open("plazza.result", std::ofstream::trunc);
  if (file.is_open())
    {
      file.close();
    }
}
