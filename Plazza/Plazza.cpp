//
// Plazza.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:19:33 2017 Arnaud WURMEL
// Last update Sat Apr 15 21:40:58 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cstdlib>
#include <unistd.h>
#include <exception>
#include "Command.hh"
#include "Parser.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "Pipe.hh"
#include "AProcess.hh"
#include "Process.hh"
#include "Plazza.hh"

Plazza::Plazza::Plazza(unsigned int maxThreads) : _maxThreads(maxThreads)
{
  std::cout << "[Plazza] instancied" << std::endl;
}

bool	Plazza::Plazza::createNewProcess()
{
  AProcess	*p = new Process(_maxThreads);
  std::shared_ptr<APipe>	pipe(new Pipe("/tmp/" + std::to_string(_process.size()) + ".fifo"));

  if (pipe->openPipe() == false ||
      p->createProcess() == false)
    {
      delete p;
      return false;
    }
  p->assignPipe(pipe);
  if (p->getPid() == 0)
    p->runProcess();
  else
    _process.push_back(std::shared_ptr<AProcess>(p));
  return true;
}

void	Plazza::Plazza::dispatchCommand(const std::vector<std::shared_ptr<Command>>& commands)
{
  PipeData<int>	data(PipeData<int>::DataType::GET_PROCESS_INFO);
  bool		shouldCreate;
  std::vector<std::shared_ptr<AProcess> >::iterator	it;
  std::vector<std::shared_ptr<Command>>::const_iterator	it_cmd;

  it_cmd = commands.begin();
  while (it_cmd != commands.end())
    {
      shouldCreate = false;
      it = _process.begin();
      while (it != _process.end())
	{
	  ++it;
	}
  
      // if (createNewProcess())
      // 	{
      // 	  *_process.back() << data;
      // 	  *_process.back() >> data;
      // 	}
      ++it_cmd;
    }

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
	dispatchCommand(commands);
	commands.clear();
      }
      catch (std::exception& e)	{
	std::cout << "\033[31m[ KO ]\033[0m\t" << e.what() << std::endl;
      }
    }
}

Plazza::Plazza::~Plazza()
{
  _process.clear();
  std::cout << "[Plazza] deleted" << std::endl;
}
