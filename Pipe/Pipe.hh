//
// Pipe.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 17:55:14 2017 Arnaud WURMEL
// Last update Tue Apr 11 20:37:31 2017 Arnaud WURMEL
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
    int		getFd() const;
    
  public:
    void	operator<<(const PipeData *);
    void	operator>>(PipeData&);

  private:
    std::string	_pipeName;
    int		_fd;
  };
}

#endif /* !PIPE_HH_ */
