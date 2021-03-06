//
// Command.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Mon Apr 10 19:58:29 2017 Arnaud WURMEL
// Last update Tue Apr 25 18:01:45 2017 baptiste
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

namespace	plz
{
  class		Command
  {
  public:
    enum	Information
      {
	PHONE_NUMBER,
	EMAIL_ADDRESS,
	IP_ADDRESS
      };

  public:
    Command();
    ~Command();

  public:
    void	addFilePath(const std::string&);
    std::vector<std::string> const&	getFilePaths() const;
    void	setCommandType(Information const&);
    Information const&	getCommandType() const;

  private:
    std::vector<std::string>	_filepaths;
    Information	_commandType;
  };
}

std::ostream& operator<<(std::ostream&, const plz::Command&);

#endif /* !COMMAND_HH_ */
