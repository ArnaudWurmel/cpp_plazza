//
// Plazza.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 10:19:33 2017 Arnaud WURMEL
// Last update Wed Apr 26 04:21:13 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cstdlib>
#include <unistd.h>
#include <exception>
#include "UIManager.hh"
#include "Logger.hh"
#include "Command.hh"
#include "Parser.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "Pipe.hh"
#include "AProcess.hh"
#include "Process.hh"
#include "Plazza.hh"
#include "StackLock.hh"

plz::Plazza::Plazza(unsigned int maxThreads) : _maxThreads(maxThreads), _manager(NULL)
{
  Logger::addLog("[Plazza] instancied");
  _manager = new UIManager(maxThreads);
  _threadData = std::unique_ptr<std::thread>(new std::thread(&Plazza::threadGetData, this));
  _threadData->detach();
}

bool	plz::Plazza::createNewProcess()
{
  AProcess	*p;

  try {
    p = new Process(_maxThreads);
    _process.push_back(std::shared_ptr<AProcess>(p));
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

void	plz::Plazza::assignCommand(std::string const& filepath,
				      Command::Information const& information,
				      std::shared_ptr<AProcess>& process)
{
  PipeData	assignCommand(PipeData::DataType::ASSIGN_ORDER);
  PipeData	filePath(PipeData::DataType::ASSIGN_ORDER);
  PipeData	status;
  
  assignCommand.setInteger(information);
  filePath.setString(filepath);
  *process << assignCommand;
  *process >> status;
  *process << filePath;
  *process >> status;
}

void	plz::Plazza::dispatchCommand(const std::vector<std::shared_ptr<Command>>& commands)
{
  StackLock	locker(_writer);
  PipeData	data(PipeData::DataType::GET_FREE_SPACE);
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
		  assignCommand(*it_filepath, (*it_cmd)->getCommandType(), *it);
		}
	      else if (status.getData()._stockage.integer == -1)
		_process.erase(it);
	      ++it;
	    }
	  if (shouldCreate && createNewProcess())
	    assignCommand(*it_filepath, (*it_cmd)->getCommandType(), _process.back());
	  ++it_filepath;
	}
      ++it_cmd;
    }
}

bool	plz::Plazza::checkExitProcess(std::vector<std::shared_ptr<AProcess> >::iterator& it)
{
  PipeData	status(PipeData::DataType::GET_PROCESS_END);

  *(*it) << status;
  *(*it) >> status;
  if (status.getData()._stockage.integer == 1 || status.getData()._stockage.integer == -1)
    {
      _process.erase(it);
      return true;
    }
  return false;
}

void	plz::Plazza::threadGetData()
{
  PipeData	getter(PipeData::DataType::GET_ORDER_STATE);
  PipeData	separator(PipeData::DataType::UNUSED);
  PipeData	data;
  PipeData	result;
  std::vector<std::shared_ptr<AProcess> >::iterator	it;

  while (true)
    {
      _writer.lock();
      it = _process.begin();
      while (it != _process.end())
      	{
	  *(*it) << getter;
	  *(*it) >> data;
	  if (data.getDataType() != PipeData::DataType::FAILURE)
	    {
	      int nb;
	      
	      *(*it) << separator;
	      for (nb = 0; nb < data.getData()._stockage.integer; nb++)
	      	{
	      	  *(*it) >> result;
	      	  std::cout << result.getData()._stockage.string << std::endl;
		  *(*it) << separator;
	      	}
	      if (data.getData()._stockage.integer > 0)
		std::cout << std::endl;
	      *(*it) >> separator;
	    }
	  if (checkExitProcess(it) == false)
	    ++it;
      	}
      _manager->updateProcess(_process);
      _writer.unlock();
    }
}

void	plz::Plazza::mainLoop()
{
  std::string	line;
  Parser	parser;
  std::vector<std::shared_ptr<Command> >	commands;

  while (std::getline(std::cin, line))
    {
      if (line.size() > 0)
	{
	  try {
	    commands = parser.evalString(line);
	    dispatchCommand(commands);
	    commands.clear();
	  }
	  catch (std::exception& e)	{
	    std::cerr << "\033[31m[ KO ]\033[0m\t" << e.what() << std::endl;
	  }
	}
    }
  while (_process.size()) {}
  _threadData.reset();
}

plz::Plazza::~Plazza()
{
  _threadData.reset();
  _process.clear();
  Logger::addLog("[Plazza] deleted");
  if (_manager)
    delete _manager;
}
