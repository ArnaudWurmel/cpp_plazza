//
// Searcher.hh for cpp_plazza in /home/baptiste/Bureau/projetTek2/cpp_plazza/Searcher
// 
// Made by baptiste
// Login   <baptiste@epitech.net>
// 
// Started on  Tue Apr 18 13:14:19 2017 baptiste
// Last update Tue Apr 18 16:21:01 2017 baptiste
//

#ifndef SEARCHER_HH_
# define SEARCHER_HH_

#include <vector>

namespace	Plazza
{
  class	Searcher
  {
  public:
    Searcher();
    ~Searcher();
    
  public:
    std::string matchPhoneNumber(std::string);
    std::string matchEmailAddress(std::string);
    std::string matchIpAddress(std::string);
    std::vector<std::string> checkInformation(Command::Information, std::vector<std::string>);
  };
}

#endif /* !SEARCHER_HH_ */
