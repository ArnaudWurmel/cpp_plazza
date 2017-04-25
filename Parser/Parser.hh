//
// Parser.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:56:42 2017 Arnaud WURMEL
// Last update Tue Apr 25 18:02:43 2017 baptiste
//

#ifndef PARSER_HH_
# define PARSER_HH_

namespace	plz
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
    std::vector<std::shared_ptr<Command> >	evalString(std::string&) const;

  private:
    std::shared_ptr<Command>	createToken(std::string&) const;

    private:
    std::map<std::string, Command::Information>	_mapping;
  };
}

#endif /* !PARSER_HH_ */
