//
// Plazza.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:19:33 2017 Arnaud WURMEL
// Last update Mon Apr 10 20:17:16 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Plazza.hh"
#include "Command.hh"
#include "Parser.hh"

Plazza::Plazza::Plazza(unsigned int maxThreads) : _maxThreads(maxThreads)
{
  std::cout << "[Plazza] instancied" << std::endl;
}

void	Plazza::Plazza::mainLoop()
{
  std::string	line;
  Parser	parser;

  while (std::getline(std::cin, line))
    {
      parser.evalString(line);
    }
}

Plazza::Plazza::~Plazza()
{
  std::cout << "[Plazza] deleted" << std::endl;
}
