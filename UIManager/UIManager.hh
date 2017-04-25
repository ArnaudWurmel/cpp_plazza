//
// UIManager.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel@epitech.net>
// 
// Started on  Tue Apr 25 09:27:49 2017 Arnaud WURMEL
// Last update Tue Apr 25 11:36:31 2017 Arnaud WURMEL
//

#ifndef UIMANAGER_HH_
# define UIMANAGER_HH_

# include <vector>
# include <memory>
# include <thread>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include "PipeData.hh"
# include "AProcess.hh"

namespace	plz
{
  class	UIManager
  {
  public:
    UIManager(unsigned int);
    ~UIManager();
    
  public:
    void	updateProcess(std::vector<std::shared_ptr<Plazza::AProcess> > const&);

  private:
    void	showData(std::vector<std::shared_ptr<Plazza::AProcess> > const&);

  private:
    unsigned int	_maxThread;

  private:
    std::unique_ptr<sf::RenderWindow>	_window;
    sf::Image				_image;
  };
}

#endif /* !UIMANAGER_HH_ */
