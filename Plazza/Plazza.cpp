//
// Plazza.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:19:33 2017 Arnaud WURMEL
// Last update Mon Apr 10 21:21:32 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <exception>
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
  std::vector<std::shared_ptr<Command> >	commands;

  while (std::getline(std::cin, line))
    {
      try {
	
	commands = parser.evalString(line);
	std::vector<std::shared_ptr<Command> >::iterator	it;
	
	it = commands.begin();
	while (it != commands.end())
	  {
	    std::cout << *(*it) << std::endl;
	    ++it;
	  }
      }
      catch (std::exception& e)
	{
	  std::cout << "\033[31m[ KO ]\033[0m\t" << e.what() << std::endl;
	}
    }
}

Plazza::Plazza::~Plazza()
{
  std::cout << "[Plazza] deleted" << std::endl;
}
