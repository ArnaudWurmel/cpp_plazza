//
// Pipe.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:55:14 2017 Arnaud WURMEL
// Last update Sat Apr 15 22:08:24 2017 Arnaud WURMEL
//

#ifndef PIPE_HH_
# define PIPE_HH_

namespace	Plazza
{
  class	Pipe : public APipe
  {
  public:
    Pipe(std::string const&);
    ~Pipe();

  public:
    bool	openPipe();
    
  public:
    void	operator<<(const PipeData<std::string>&);
    void	operator>>(PipeData<std::string>&);
    void	operator<<(const PipeData<int>&);
    void	operator>>(PipeData<int>&);

  private:
    std::string	_pipeName;
  };
}

#endif /* !PIPE_HH_ */
