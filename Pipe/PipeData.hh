//
// PipeData.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 20:16:58 2017 Arnaud WURMEL
// Last update Tue Apr 11 20:24:07 2017 Arnaud WURMEL
//

#ifndef APIPEDATA_HH_
# define APIPEDATA_HH_

namespace	Plazza
{
  class	PipeData
  {
  public:
    enum	DataType
      {
	GET_PROCESS_INFO,
	SEND_DATA
      };
  public:
    PipeData();
    ~PipeData();

  public:
    std::string	getString() const;
    DataType const&	getDataType() const;
    Command::Information	getInformation() const;
  };
}

#endif /* !APIPEDATA_HH_ */
