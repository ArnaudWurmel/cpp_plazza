//
// Searcher.cpp for  in /home/baptiste/Bureau/projetTek2/cpp_plazza/Searcher
// 
// Made by baptiste
// Login   <baptiste@epitech.net>
// 
// Started on  Tue Apr 18 13:05:38 2017 baptiste
// Last update Wed Apr 19 13:49:10 2017 baptiste
//

#include <regex>
#include <fstream>
#include <string>
#include "Searcher.hh"

Plazza::Searcher::Searcher()
{
}

void	Plazza::Searcher::matchPhoneNumber(std::string str, std::vector<std::string>& vec)
{
  std::regex	check_number("(([0][1-9]) ?([0-9 ]{2}) ?([0-9 ]{2}) ?([0-9]{2}) ?([0-9]{2}))");
  std::smatch	number;

  while (std::regex_search(str, number, check_ip))
    {
      vec.push_back(number[0]);
      str = number.suffix().str();
    }
}

void	Plazza::Searcher::matchEmailAddress(std::string str, std::vector<std::string>& vec)
{
  std::regex	check_mail("([a-zA-Z0-9_.-]+)@((?:[a-zA-Z0-9]+.)+)([a-zA-Z0-9]{1,4})");
  std::smatch	mail;

  while (std::regex_search(str, mail, check_ip))
    {
      vec.push_back(mail[0]);
      str = mail.suffix().str();
    }
}

void	Plazza::Searcher::matchIpAddress(std::string str, std::vector<std::string>& vec)
{
  std::regex	check_ip("(^[2][5][0-5].|^[2][0-4][0-9].|^[1][0-9][0-9].|^[0-9][0-9].|^[0-9].)([2][0-5][0-5].|[2][0-4][0-9].|[1][0-9][0-9].|[0-9][0-9].|[0-9].)([2][0-5][0-5].|[2][0-4][0-9].|[1][0-9][0-9].|[0-9][0-9].|[0-9].)([2][0-5][0-5]|[2][0-4][0-9]|[1][0-9][0-9]|[0-9][0-9]|[0-9])");
  std::smatch	ip;

  while (std::regex_search(str, ip, check_ip))
    {
      vec.push_back(ip[0]);
      str = ip.suffix().str();
    }
}

std::vector<std::string>	Plazza::Searcher::checkInformation(Command::Information inf, std::vector<std::string> file)
{
  std::ifstream			fichier(file.front.c_str(), ios::in);
  std::vector<std::string>	ret;
  std::string			all_file;
  
  if (fichier)
    {
      all_file = getline(fichier, all_file, '\0');
      if (inf == Plazza::Command::Inforamtion::PHONE_NUMBER)
	this.matchPhoneNumber(all_file, ret)
      else if (inf == Plazza::Command::Inforamtion::EMAIL_ADDRESS)
	this.matchEmailAddress(all_file, ret);
      else
	this.matchIpAddress(all_file, ret);
    }
  return (ret);
}

Plazza::Searcher::~Searcher() {}
