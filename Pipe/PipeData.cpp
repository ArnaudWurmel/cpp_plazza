//
// PipeData.cpp for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Apr 12 15:15:26 2017 Arnaud WURMEL
// Last update Sat Apr 15 22:18:48 2017 Arnaud WURMEL
//

#include <vector>
#include <iostream>
#include <cstring>
#include "Command.hh"
#include "PipeData.hh"

// template<typename T>
// Plazza::PipeData<T>::PipeData()
// {
//   memset(&_data, 0, sizeof(_data));
// }

// template<typename T>
// Plazza::PipeData<T>::PipeData(Plazza::PipeData::DataType const& type)
// {
//   memset(&_data, 0, sizeof(_data));
//   _data._type = type;
// }

// template<class T>
// Plazza::PipeData<T>::PipeData()
// {
//   memset(&_data, 0, sizeof(_data));
// }

// Plazza::PipeData::Data const&	Plazza::PipeData::getData() const
// {
//   return _data;
// }

//template<class T>
//Plazza::PipeData<T>::~PipeData() {}

template class Plazza::PipeData<int>;
template class Plazza::PipeData<std::string>;
