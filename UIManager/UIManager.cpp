//
// UIManager.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel@epitech.net>
// 
// Started on  Tue Apr 25 09:27:26 2017 Arnaud WURMEL
// Last update Wed Apr 26 11:46:25 2017 Arnaud WURMEL
//

#ifdef UIMODE

#include <iostream>
#include "UIManager.hh"

plz::UIManager::UIManager(unsigned int maxThread) : _maxThread(maxThread)
{
  sf::VideoMode	mode(600, 600);

  _color[BACKGROUND] = sf::Color(44, 62, 80);
  _color[PROCESS_BACKGROUND] = sf::Color(236, 240, 241);
  _color[THREAD_USED] = sf::Color(231, 76, 60);
  _color[THREAD_UNUSED] = sf::Color(39, 174, 96);
  _window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(mode, "Plazza"));
  _image.create(600, 600);
}

void	plz::UIManager::updateProcess(std::vector<std::shared_ptr<plz::AProcess> > const& processList)
{
  sf::Texture	texture;
  sf::Sprite	sprite;

  _window->setFramerateLimit(60);
  texture.loadFromImage(_image);
  sprite.setTexture(texture);
  sf::Event	e;
  
  while (_window->pollEvent(e)) {}
  showData(processList);
  _window->clear(_color[BACKGROUND]);
  _window->draw(sprite);
  _window->display();
}

void	plz::UIManager::showData(std::vector<std::shared_ptr<plz::AProcess> > const&	processList)
{
  std::vector<std::shared_ptr<plz::AProcess> >::const_iterator	it;
  plz::PipeData	getStatus(PipeData::DataType::GET_PROCESS_INFO);
  plz::PipeData	value;
  unsigned int	nbSquare;
  unsigned int	idx;
  unsigned int	idx_thread;
  unsigned int	squareSize;
  unsigned int	squareThreadSize;
  unsigned int	nbSquareProcess;

  drawSquare(0, 0, _image.getSize().x, BACKGROUND);
  if ((nbSquare = getNbSquare(processList.size())) > 0)
    {
      squareSize = _image.getSize().x / nbSquare;
      nbSquareProcess = getNbSquare(_maxThread);
      squareThreadSize = (squareSize - 10) / nbSquareProcess;
      it = processList.begin();
      idx = 0;
      while (it != processList.end())
      	{
	  drawSquare((idx % nbSquare) * squareSize, (idx / nbSquare) * squareSize,
		     squareSize, PROCESS_BACKGROUND);
	  *(*it) << getStatus;
	  *(*it) >> value;
	  idx_thread = 0;
	  while (idx_thread < _maxThread)
	    {
	      if (nbSquare > 0)
		{
		  unsigned int	x = (5 + (idx % nbSquare) * squareSize) + (idx_thread % nbSquareProcess) * squareThreadSize;
		  unsigned int	y = (5 + (idx / nbSquare) * squareSize) + (idx_thread / nbSquareProcess) * squareThreadSize;
		  if (idx_thread < _maxThread - value.getInteger())
		    drawSquare(x, y, squareThreadSize, THREAD_USED);
		  else
		    drawSquare(x, y, squareThreadSize, THREAD_UNUSED);
		}
	      ++idx_thread;
	    }
	  ++idx;
	  ++it;
      	}
    }
}

unsigned int	plz::UIManager::getNbSquare(unsigned int nbProcess)
{
  unsigned int	value;

  if (nbProcess > 0)
    {
      value = 1;
      while (nbProcess > (value * value))
	value += 1;
      return value;
    }
  return 0;
}

void	plz::UIManager::drawSquare(unsigned int x, unsigned int y, unsigned int size, Color const& color)
{
  unsigned int	idx_y;
  unsigned int	idx_x;

  idx_y = 0;
  while (idx_y < size)
    {
      idx_x = 0;
      while (idx_x < size)
	{
	  if (idx_x != 0 && idx_x + 1 != size && idx_y != 0 && idx_y + 1 != size)
	    _image.setPixel(x + idx_x, y + idx_y, _color[color]);
	  ++idx_x;
	}
      ++idx_y;
    }
}

plz::UIManager::~UIManager() {}

#endif
