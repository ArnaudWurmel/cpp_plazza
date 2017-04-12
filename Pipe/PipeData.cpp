//
// PipeData.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Apr 12 15:15:26 2017 Arnaud WURMEL
// Last update Wed Apr 12 17:35:43 2017 Arnaud WURMEL
//

#include <vector>
#include <iostream>
#include <cstring>
#include "Command.hh"
#include "PipeData.hh"

Plazza::PipeData::PipeData()
{
  _str = "";
  memset(&_data, 0, sizeof(_data));
  _data._type = Plazza::PipeData::DataType::UNUSED;
  _data._inf = Plazza::Command::PHONE_NUMBER;
}

Plazza::PipeData::Data const&	Plazza::PipeData::getData() const
{
  return _data;
}

std::string const&	Plazza::PipeData::getString() const
{
  return _str;
}

Plazza::PipeData::DataType const&	Plazza::PipeData::getDataType() const
{
  return _data._type;
}

Plazza::Command::Information const&	Plazza::PipeData::getInformation() const
{
  return _data._inf;
}

void	Plazza::PipeData::setString(const std::string& str)
{
  _str = str;
  _str.copy(_data._str, MAX_DATA);
}

void	Plazza::PipeData::setDataType(Plazza::PipeData::DataType const& type)
{
  _data._type = type;
}

void	Plazza::PipeData::setInformation(Command::Information const& inf)
{
  _data._inf = inf;
}

Plazza::PipeData::~PipeData() {}