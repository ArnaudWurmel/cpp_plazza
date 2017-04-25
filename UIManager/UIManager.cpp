//
// UIManager.cpp for cpp_plazza in /home/wurmel/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel@epitech.net>
// 
// Started on  Tue Apr 25 09:27:26 2017 Arnaud WURMEL
// Last update Tue Apr 25 11:36:03 2017 Arnaud WURMEL
//

#include <iostream>
#include "UIManager.hh"

plz::UIManager::UIManager(unsigned int maxThread) : _maxThread(maxThread)
{
  sf::VideoMode	mode(600, 600);

  _window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(mode, "Plazza"));
  _image.create(600, 600);
}

void	plz::UIManager::updateProcess(std::vector<std::shared_ptr<Plazza::AProcess> > const& processList)
{
  sf::Texture	texture;
  sf::Sprite	sprite;

  _window->setFramerateLimit(60);
  texture.loadFromImage(_image);
  sprite.setTexture(texture);
  sf::Event	e;
  
  while (_window->pollEvent(e)) {}
  showData(processList);
  _window->clear();
  _window->draw(sprite);
  _window->display();
}

void	plz::UIManager::showData(std::vector<std::shared_ptr<Plazza::AProcess> > const&	processList)
{
  std::cout << processList.size() << std::endl;
}

plz::UIManager::~UIManager() {}
