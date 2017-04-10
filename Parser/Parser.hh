//
// Parser.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:56:42 2017 Arnaud WURMEL
// Last update Mon Apr 10 20:33:57 2017 Arnaud WURMEL
//

#ifndef PARSER_HH_
# define PARSER_HH_

namespace	Plazza
{
  class	Parser
  {
  public:
    Parser();
    ~Parser();

  private:
    void	epurStr(std::string&) const;
    bool	isCharacterAfter(std::string::iterator, const std::string::iterator&) const;
    
  public:
    std::vector<std::unique_ptr<Command> >	evalString(std::string&) const;
  };
}

#endif /* !PARSER_HH_ */
