//
// PipeData.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Apr 12 15:15:26 2017 Arnaud WURMEL
// Last update Tue Apr 25 17:47:04 2017 baptiste
//

#include <vector>
#include <iostream>
#include <cstring>
#include "Command.hh"
#include "PipeData.hh"

plz::PipeData::PipeData()
{
  memset(&_data, 0, sizeof(_data));
}

plz::PipeData::PipeData(plz::PipeData::DataType const& type)
{
  memset(&_data, 0, sizeof(_data));
  _data._type = type;
}

plz::PipeData::Data const&	plz::PipeData::getData() const
{
  return _data;
}

plz::PipeData::DataType const&	plz::PipeData::getDataType() const
{
  return _data._type;
}

void	plz::PipeData::setInteger(uint32_t value)
{
  _data._stockage.integer = value;
}

void	plz::PipeData::setString(std::string const& value)
{
  value.copy(_data._stockage.string, MAX_SIZE, 0);
}

void	plz::PipeData::setDataType(plz::PipeData::DataType const& type)
{
  _data._type = type;
}

void	plz::PipeData::setStockage(DataStockage const& stockage)
{
  _data._stockage = stockage;
}

plz::PipeData::~PipeData() {}
