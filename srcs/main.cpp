//
// main.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 12:46:29 2017 Arnaud WURMEL
// Last update Mon Apr 10 13:18:31 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include <memory>
#include "Plazza.hh"

static bool	check_arg(const char *arg)
{
  if (std::stoi(arg, nullptr) <= 0)
    return false;
  return true;
}

int	main(int ac, char **av)
{
  std::unique_ptr<Plazza::Plazza>	plazza;

  if (ac != 2 || check_arg(av[1]) == false)
    {
      std::cerr << "Usage:" << std::endl;
      std::cout<< av[0] << " [NB_THREAD_BY_PROCESS > 0]" << std::endl;
      return 1;
    }
  plazza = std::unique_ptr<Plazza::Plazza>(new Plazza::Plazza(std::stoi(av[1], nullptr)));
  plazza->mainLoop();
  return 0;
}
