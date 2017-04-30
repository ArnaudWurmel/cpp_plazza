//
// Searcher.cpp for  in /home/baptiste/Bureau/projetTek2/cpp_plazza/Searcher
// 
// Made by baptiste
// Login   <baptiste@epitech.net>
// 
// Started on  Tue Apr 18 13:05:38 2017 baptiste
// Last update Sun Apr 30 22:49:54 2017 Arnaud WURMEL
//

#include <regex>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Searcher.hh"

plz::Searcher::Searcher()
{
}

void		plz::Searcher::XOR_1byte(std::regex reg, std::string str, std::vector<std::string>& vec, bool& ret) const
{
  std::string   res_str;
  std::smatch	number;
  int           key = 0;
  int           i;

  while (key <= 255)
    {
      i = 0;
      res_str = "";
      while (str[i] != '\0')
	{
	  res_str += str[i] ^ key;
	  i++;
	}
      while (std::regex_search(res_str, number, reg))
	{
	  vec.push_back(number[0]);
	  res_str = number.suffix().str();
	  ret = true;
	}
      if (ret == true)
	return ;
      key++;
    }
}

void     plz::Searcher::XOR_2byte(std::regex reg, std::string str, std::vector<std::string>& vec, bool& ret) const
{
  std::string   res_str;
  std::smatch	number;
  int           key = 0;
  int           key2;
  int           i;

  while (key <= 255)
    {
      key2 = 0;
      while (key2 <= 255)
	{
	  i = 0;
	  res_str = "";
	  while (str[i] != '\0')
	    {
	      res_str += str[i] ^ key;
	      i++;
	    }
	  while (std::regex_search(res_str, number, reg))
	    {
	      vec.push_back(number[0]);
	      res_str = number.suffix().str();
	      ret = true;
	    }
	  if (ret == true)
	    return ;
	  key2++;
	}
      key++;
    }
}

void		plz::Searcher::cesar(std::regex reg, std::string str, std::vector<std::string>& vec, bool& ret) const
{
  std::string   res_str;
  std::smatch	number;
  int           key = 0;
  int           i;

  while (key < 128)
    {
      i = 0;
      res_str = "";
      while (str[i] != '\0')
	{
	  res_str += (str[i] + key) % 128;
	  i++;
	}
      while (std::regex_search(res_str, number, reg))
	{
	  vec.push_back(number[0]);
	  res_str = number.suffix().str();
	  ret = true;
	}
      if (ret == true)
	return ;
      key++;
    }
}

void	plz::Searcher::matchPhoneNumber(std::string str, std::vector<std::string>& vec) const
{
  std::string	reg = "(([0][1-9]) ?([0-9]{2}) ?([0-9]{2}) ?([0-9]{2}) ?([0-9]{2}))";
  std::regex	check_number(reg);
  std::smatch	number;
  #ifdef UIMODE
  bool		find = false;
  #endif

  while (std::regex_search(str, number, check_number))
    {
      vec.push_back(number[0]);
      str = number.suffix().str();
      #ifdef UIMODE
      find = true;
      #endif
    }
  #ifdef UIMODE
  if (find == false)
    this->cesar(check_number, str, vec, find);
  if (find == false)
    this->XOR_1byte(check_number, str, vec, find);
  if (find == false)
    this->XOR_2byte(check_number, str, vec, find);
  #endif
}

void	plz::Searcher::matchEmailAddress(std::string str, std::vector<std::string>& vec) const
{
  std::string	reg = "([a-zA-Z0-9_.-]+)@((?:[a-zA-Z0-9]+.)+)([a-zA-Z0-9]{1,4})";
  std::regex	check_mail(reg);
  std::smatch	mail;
  #ifdef UIMODE
  bool		find = false;
  #endif

  while (std::regex_search(str, mail, check_mail))
    {
      vec.push_back(mail[0]);
      str = mail.suffix().str();
      #ifdef UIMODE
      find = true;
      #endif
    }
  #ifdef UIMODE
  if (find == false)
    this->cesar(check_mail, str, vec, find);
  if (find == false)
    this->XOR_1byte(check_mail, str, vec, find);
  if (find == false)
    this->XOR_2byte(check_mail, str, vec, find);
  #endif
}

void	plz::Searcher::matchIpAddress(std::string str, std::vector<std::string>& vec) const
{
  std::string	reg = "((1[0-9][0-9])|(2[0-4][0-9])|(2(5[0-5]))|([0-9][0-9])|([0-9]))\\.((1[0-9][0-9])|(2[0-4][0-9])|(2(5[0-5]))|([0-9][0-9])|([0-9]))\\.((1[0-9][0-9])|(2[0-4][0-9])|(2(5[0-5]))|([0-9][0-9])|([0-9]))\\.((1[0-9][0-9])|(2[0-4][0-9])|(2(5[0-5]))|([0-9][0-9])|([0-9]))";
  std::regex	check_ip(reg);
  std::smatch	ip;
  #ifdef UIMODE
  bool		find = false;
  #endif

  while (std::regex_search(str, ip, check_ip))
    {
      vec.push_back(ip[0]);
      str = ip.suffix().str();
      #ifdef UIMODE
      find = true;
      #endif
    }
  #ifdef UIMODE
  if (find == false)
    this->cesar(check_ip, str, vec, find);
  if (find == false)
    this->XOR_1byte(check_ip, str, vec, find);
  if (find == false)
    this->XOR_2byte(check_ip, str, vec, find);
  #endif
}

std::vector<std::string>	plz::Searcher::checkInformation(Command::Information inf, std::string file) const
{
  std::ifstream			fichier(file, std::ios::in);
  std::vector<std::string>	ret;
  std::string			all_file;
  
  if (fichier)
    {
      getline(fichier, all_file, '\0');
      if (inf == plz::Command::Information::PHONE_NUMBER)
	this->matchPhoneNumber(all_file, ret);
      else if (inf == plz::Command::Information::EMAIL_ADDRESS)
	this->matchEmailAddress(all_file, ret);
      else
	this->matchIpAddress(all_file, ret);
    }
  return (ret);
}

plz::Searcher::~Searcher() {}
