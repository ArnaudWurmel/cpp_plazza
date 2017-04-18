//
// PipeData.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Apr 12 15:15:26 2017 Arnaud WURMEL
// Last update Tue Apr 18 11:16:38 2017 Arnaud WURMEL
//

#include <vector>
#include <iostream>
#include <cstring>
#include "Command.hh"
#include "PipeData.hh"

Plazza::PipeData::PipeData()
{
  memset(&_data, 0, sizeof(_data));
}

Plazza::PipeData::PipeData(Plazza::PipeData::DataType const& type)
{
  memset(&_data, 0, sizeof(_data));
  _data._type = type;
}

Plazza::PipeData::Data const&	Plazza::PipeData::getData() const
{
  return _data;
}

Plazza::PipeData::DataType const&	Plazza::PipeData::getDataType() const
{
  return _data._type;
}

void	Plazza::PipeData::setInteger(uint32_t value)
{
  _data._stockage.integer = value;
}

void	Plazza::PipeData::setString(std::string const& value)
{
  value.copy(_data._stockage.string, MAX_SIZE, 0);
}

void	Plazza::PipeData::setDataType(Plazza::PipeData::DataType const& type)
{
  _data._type = type;
}

void	Plazza::PipeData::setStockage(DataStockage const& stockage)
{
  _data._stockage = stockage;
}

Plazza::PipeData::~PipeData() {}
