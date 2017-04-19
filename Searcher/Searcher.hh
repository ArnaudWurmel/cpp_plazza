//
// Searcher.hh for cpp_plazza in /home/baptiste/Bureau/projetTek2/cpp_plazza/Searcher
// 
// Made by baptiste
// Login   <baptiste@epitech.net>
// 
// Started on  Tue Apr 18 13:14:19 2017 baptiste
// Last update Wed Apr 19 13:45:20 2017 baptiste
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
    void	matchPhoneNumber(std::string, std::vector<std::string>&);
    void	matchEmailAddress(std::string, std::vector<std::string>&);
    void	matchIpAddress(std::string, std::vector<std::string>&);
    std::vector<std::string> checkInformation(Command::Information, std::vector<std::string>);
  };
}

#endif /* !SEARCHER_HH_ */
