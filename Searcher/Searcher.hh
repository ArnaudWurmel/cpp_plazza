//
// Searcher.hh for cpp_plazza in /home/baptiste/Bureau/projetTek2/cpp_plazza/Searcher
// 
// Made by baptiste
// Login   <baptiste@epitech.net>
// 
// Started on  Tue Apr 18 13:14:19 2017 baptiste
// Last update Sun Apr 30 05:04:37 2017 Arnaud WURMEL
//

#ifndef SEARCHER_HH_
# define SEARCHER_HH_

#include <vector>
#include <regex>
#include "Command.hh"

namespace	plz
{
  class	Searcher
  {
  public:
    Searcher();
    ~Searcher();
    
  public:
    void	XOR_1byte(std::regex, std::string, std::vector<std::string>&, bool&) const;
    void	XOR_2byte(std::regex, std::string, std::vector<std::string>&, bool&) const;
    void	cesar(std::regex, std::string, std::vector<std::string>&, bool&) const;
    void	matchPhoneNumber(std::string, std::vector<std::string>&) const;
    void	matchEmailAddress(std::string, std::vector<std::string>&) const;
    void	matchIpAddress(std::string, std::vector<std::string>&) const;
    std::vector<std::string> checkInformation(Command::Information, std::string) const;
  };
}

#endif /* !SEARCHER_HH_ */
