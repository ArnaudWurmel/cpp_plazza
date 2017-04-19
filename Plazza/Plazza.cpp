//
// Plazza.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:19:33 2017 Arnaud WURMEL
// Last update Wed Apr 19 13:05:56 2017 Arnaud WURMEL
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
#include "StackLock.hh"

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
  StackLock	locker(_writer);
  PipeData	data(PipeData::DataType::GET_PROCESS_INFO);
  PipeData	status;
  bool		shouldCreate;
  std::vector<std::shared_ptr<AProcess> >::iterator	it;
  std::vector<std::shared_ptr<Command>>::const_iterator	it_cmd;
  std::vector<std::string>::const_iterator	it_filepath;
  std::shared_ptr<AProcess>	process;

  it_cmd = commands.begin();
  while (it_cmd != commands.end())
    {
      it_filepath = (*it_cmd)->getFilePaths().begin();
      while (it_filepath != (*it_cmd)->getFilePaths().end())
	{
	  shouldCreate = true;
	  it = _process.begin();
	  while (shouldCreate && it != _process.end())
	    {
	      *(*it) << data;
	      *(*it) >> status;
	      if (status.getData()._stockage.integer > 0)
		{
		  shouldCreate = false;
		  PipeData	assignCommand(PipeData::DataType::ASSIGN_ORDER);
		  PipeData	filePath(PipeData::DataType::ASSIGN_ORDER);

		  assignCommand.setInteger((*it_cmd)->getCommandType());
		  filePath.setString(*it_filepath);
		  *(*it) << assignCommand;
		  *(*it) >> status;
		  *(*it) << filePath;
		  *(*it) >> status;
		}
	      ++it;
	    }
	  if (shouldCreate && createNewProcess())
	    {
	      PipeData	assignCommand(PipeData::DataType::ASSIGN_ORDER);
	      PipeData	filePath(PipeData::DataType::ASSIGN_ORDER);

	      assignCommand.setInteger((*it_cmd)->getCommandType());
	      filePath.setString(*it_filepath);
	      *_process.back() << assignCommand;
	      *_process.back() >> status;
	      *_process.back() << filePath;
	      *_process.back() >> status;
	    }
	  ++it_filepath;
	}
      ++it_cmd;
    }
}

void	Plazza::Plazza::threadGetData()
{
  while (1)
    {
      std::cout << "Start locking mutex" << std::endl;
      _writer.lock();
      std::cout << "Mutex acquired" << std::endl;
      _writer.unlock();
      std::cout << "Mutex unlocked" << std::endl;
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
