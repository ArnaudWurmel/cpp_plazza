//
// main.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 12:46:29 2017 Arnaud WURMEL
// Last update Tue Apr 25 13:24:59 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Command.hh"
#include "PipeData.hh"
#include "APipe.hh"
#include "AProcess.hh"
#include "Command.hh"
#include "Plazza.hh"

static bool	check_arg(const char *arg)
{
  if (std::stoi(arg, nullptr) <= 0)
    return false;
  return true;
}

int	main(int ac, char **av)
{
  std::unique_ptr<plz::Plazza>	plazza;

  if (ac != 2 || check_arg(av[1]) == false)
    {
      std::cerr << "Usage:" << std::endl;
      std::cerr << av[0] << " [NB_THREAD_BY_PROCESS > 0]" << std::endl;
      return 1;
    }
  plazza = std::unique_ptr<plz::Plazza>(new plz::Plazza(std::stoi(av[1], nullptr)));
  plazza->mainLoop();
  return 0;
}
