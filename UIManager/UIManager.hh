//
// UIManager.hh for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel@epitech.net>
// 
// Started on  Tue Apr 25 09:27:49 2017 Arnaud WURMEL
// Last update Wed Apr 26 08:45:32 2017 Arnaud WURMEL
//

#ifndef UIMANAGER_HH_
# define UIMANAGER_HH_

#ifdef UIMODE

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
    enum	Color
      {
	BACKGROUND = 0,
	PROCESS_BACKGROUND,
	THREAD_USED,
	THREAD_UNUSED
      };
  public:
    UIManager(unsigned int);
    ~UIManager();
    
  public:
    void	updateProcess(std::vector<std::shared_ptr<plz::AProcess> > const&);

  private:
    void	showData(std::vector<std::shared_ptr<plz::AProcess> > const&);

  private:
    unsigned int	getNbSquare(unsigned int);
    void		drawSquare(unsigned int, unsigned int, unsigned int, Color const&);

  private:
    unsigned int	_maxThread;

  private:
    std::unique_ptr<sf::RenderWindow>	_window;
    sf::Image				_image;
    sf::Color				_color[4];
  };
}

#endif
#endif /* !UIMANAGER_HH_ */
