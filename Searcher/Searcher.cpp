//
// Searcher.cpp for  in /home/baptiste/Bureau/projetTek2/cpp_plazza/Searcher
// 
// Made by baptiste
// Login   <baptiste@epitech.net>
// 
// Started on  Tue Apr 18 13:05:38 2017 baptiste
// Last update Tue Apr 25 17:35:00 2017 baptiste
//

#include <regex>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Searcher.hh"

plz::Searcher::Searcher()
{
}

void    plz::Searcher::XOR_change(std::string buf, std::string buf2, std::string& res)
{
  int   i = 0;

  res = "";
  while (buf[i] != '\0')
    {
      if (buf[i] == buf2[i])
	res += '1';
      else
	res += '0';
      i++;
    }
}

void    plz::Searcher::itoa(char c, std::string& str)
{
  int   i = 7;
  
  str = "";
  while (i >= 0)
    {
      str += ((c & (1 << i))? '1' : '0');
      i--;
    }
}

void		plz::Searcher::XOR_1byte(std::regex reg, std::string str, std::vector<std::string>& vec, bool& ret)
{
  std::string   buffer;
  std::string   buffer2;
  std::string   res;
  std::string   res_str;
  std::smatch	number;
  int           key = 0;
  int           i;

  while (key <= 127)
    {
      i = 0;
      res_str = "";
      while (str[i] != '\0')
	{
	  itoa(str[i], buffer);
	  itoa(key, buffer2);
	  XOR_change(buffer, buffer2, res);
	  res_str += std::strtol(res.c_str(), 0, 2);
	  i++;
	}
      while (std::regex_search(res_str, number, reg))
	{
	  vec.push_back(number[0]);
	  res_str = number.suffix().str();
	  ret = true;
	}
      key++;
    }
}

void     plz::Searcher::XOR_2byte(std::regex reg, std::string str, std::vector<std::string>& vec, bool& ret)
{
  std::string   buffer;
  std::string   buffer2;
  std::string   buffer3;
  std::string   res;
  std::string   res_str;
  std::smatch	number;
  int           key = 0;
  int           key2 = 0;
  int           i;

  while (key <= 127)
    {
      key2 = 0;
      while (key2 <= 127)
	{
	  i = 0;
	  res_str = "";
	  while (str[i] != '\0')
	    {
	      itoa(str[i], buffer);
	      itoa(key, buffer2);
	      itoa(key2, buffer3);
	      if ((i % 2) == 0)
		XOR_change(buffer, buffer2, res);
	      else
		XOR_change(buffer, buffer3, res);
	      res_str += std::strtol(res.c_str(), 0, 2);
	      i++;
	    }
	  while (std::regex_search(res_str, number, reg))
	    {
	      vec.push_back(number[0]);
	      res_str = number.suffix().str();
	      ret = true;
	    }
	  key2++;
	}
      key++;
    }
}

void		plz::Searcher::cesar(std::regex reg, std::string str, std::vector<std::string>& vec, bool& ret)
{
  std::smatch	number;

  while (std::regex_search(str, number, reg))
    {
      vec.push_back(number[0]);
      str = number.suffix().str();
      ret = true;
    }
}

void	plz::Searcher::matchPhoneNumber(std::string str, std::vector<std::string>& vec)
{
  std::string	reg = "(([0][1-9]) ?([0-9]{2}) ?([0-9]{2}) ?([0-9]{2}) ?([0-9]{2}))";
  std::string	reg2 = "000100101001000101000001000101000001000101000001000101000000";
  std::regex	check_number(reg);
  std::smatch	number;
  bool		find = false;
  int		key = 0;
  int		i;

  while (std::regex_search(str, number, check_number))
    {
      vec.push_back(number[0]);
      str = number.suffix().str();
      find = true;
    }
  if (find == true)
    return ;
  while (key < 128)
    {
      i = 0;
      while (reg[i] != '\0')
	{
	  if (reg2[i] == '1')
	    reg[i] = (reg[i] + key) % 128;
	  i++;
	}
      
      std::regex	check_number(reg);
      
      while (std::regex_search(str, number, check_number))
	{
	  vec.push_back(number[0]);
	  str = number.suffix().str();
	  find = true;
	}
      key++;
    }
  // if (find == false)
  //   this->cesar(check_number, str, vec, find);
  // if (find == false)
  //   this->XOR_1byte(check_number, str, vec, find);
  // if (find == false)
  //   this->XOR_2byte(check_number, str, vec, find);
}

void	plz::Searcher::matchEmailAddress(std::string str, std::vector<std::string>& vec)
{
  std::string	reg = "([a-zA-Z0-9_.-]+)@((?:[a-zA-Z0-9]+.)+)([a-zA-Z0-9]{1,4})";
  std::string	reg2 = "00101101101111000100000101101101001000001011011010000000";
  std::regex	check_mail(reg);
  std::smatch	mail;
  bool		find = false;
  int		key = 0;
  int		i;

  while (std::regex_search(str, mail, check_mail))
    {
      vec.push_back(mail[0]);
      str = mail.suffix().str();
      find = true;
    }
  if (find == true)
    return ;
  while (key < 128)
    {
      i = 0;
      while (reg[i] != '\0')
	{
	  if (reg2[i] == '1')
	    reg[i] = (reg[i] + key) % 128;
	  i++;
	}
      
      std::regex	check_mail(reg);
      
      while (std::regex_search(str, mail, check_mail))
	{
	  vec.push_back(mail[0]);
	  str = mail.suffix().str();
	  find = true;
	}
      key++;
    }
  // if (find == false)
  //   this->cesar(check_mail, str, vec, find);
  // if (find == false)
  //   this->XOR_1byte(check_mail, str, vec, find);
  // if (find == false)
  //   this->XOR_2byte(check_mail, str, vec, find);
}

void	plz::Searcher::matchIpAddress(std::string str, std::vector<std::string>& vec)
{
  std::string	reg = "([0-2]?[0-9]?[0-9](\\.[0-2]?[0-9]?[0-9]){3})";
  std::string	reg2 = "00101000101000101000010101000101000101000000";
  std::regex	check_ip(reg);
  std::smatch	ip;
  bool		find = false;
  int		key = 0;
  int		i;

  while (std::regex_search(str, ip, check_ip))
    {
      vec.push_back(ip[0]);
      str = ip.suffix().str();
      find = true;
    }
  if (find == true)
    return ;
  while (key < 128)
    {
      i = 0;
      while (reg[i] != '\0')
	{
	  if (reg2[i] == '1')
	    reg[i] = (reg[i] + key) % 128;
	  i++;
	}

      std::regex	check_ip(reg);
      
      while (std::regex_search(str, ip, check_ip))
	{
	  vec.push_back(ip[0]);
	  str = ip.suffix().str();
	  find = true;
	}
      key++;
    }
  // if (find == false)
  //   this->cesar(check_ip, str, vec, find);
  // if (find == false)
  //   this->XOR_1byte(check_ip, str, vec, find);
  // if (find == false)
  //   this->XOR_2byte(check_ip, str, vec, find);
}

std::vector<std::string>	plz::Searcher::checkInformation(Command::Information inf, std::string file)
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
