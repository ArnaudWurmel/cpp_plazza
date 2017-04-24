//
// Searcher.hh for cpp_plazza in /home/baptiste/Bureau/projetTek2/cpp_plazza/Searcher
// 
// Made by baptiste
// Login   <baptiste@epitech.net>
// 
// Started on  Tue Apr 18 13:14:19 2017 baptiste
// Last update Mon Apr 24 13:56:18 2017 baptiste
//

#ifndef SEARCHER_HH_
# define SEARCHER_HH_

#include <vector>
#include <regex>
#include "Command.hh"

namespace	Plazza
{
  class	Searcher
  {
  public:
    Searcher();
    ~Searcher();
    
  public:
    void	XOR_change(std::string, std::string, std::string&);
    void	itoa(char, std::string&);
    void	XOR_1byte(std::regex, std::string, std::vector<std::string>&, bool&);
    void	XOR_2byte(std::regex, std::string, std::vector<std::string>&, bool&);
    void	cesar(std::regex, std::string, std::vector<std::string>&, bool&);
    void	matchPhoneNumber(std::string, std::vector<std::string>&);
    void	matchEmailAddress(std::string, std::vector<std::string>&);
    void	matchIpAddress(std::string, std::vector<std::string>&);
    std::vector<std::string> checkInformation(Command::Information, std::string);
  };
}

#endif /* !SEARCHER_HH_ */
