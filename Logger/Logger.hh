//
// Logger.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Thu Apr 20 09:36:05 2017 Arnaud WURMEL
// Last update Fri Apr 28 23:44:46 2017 Arnaud WURMEL
//

#ifndef LOGGER_HH_
# define LOGGER_HH_

# include <fstream>

namespace	plz
{
  class		Logger
  {
  public:
    static void	addLog(std::string const&);
    static void	resetLogFile();

    static void	addResult(std::string const&);
    static void	endResult();
  };
}

#endif /* !LOGGER_HH_ */
