//
// Plazza.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:19:33 2017 Arnaud WURMEL
// Last update Mon Apr 10 13:21:22 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include "Plazza.hh"

Plazza::Plazza::Plazza(unsigned int maxThreads) : _maxThreads(maxThreads)
{
  std::cout << "[Plazza] instancied" << std::endl;
}

void	Plazza::Plazza::mainLoop()
{
  std::string	line;

  while (std::getline(std::cin, line))
    {
      
    }
}

Plazza::Plazza::~Plazza()
{
  std::cout << "[Plazza] deleted" << std::endl;
}
