//
// PipeData.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 20:16:58 2017 Arnaud WURMEL
// Last update Wed Apr 12 17:37:23 2017 Arnaud WURMEL
//

#ifndef APIPEDATA_HH_
# define APIPEDATA_HH_

# define MAX_DATA 1024

namespace	Plazza
{
  class	PipeData
  {
  public:
    enum	DataType : int
      {
	UNUSED = 0,
	GET_PROCESS_INFO,
	SEND_DATA
      };
    
  public:
    struct	Data
    {
      DataType		_type;
      Command::Information	_inf;
      char		_str[MAX_DATA];
    };

  public:
    PipeData();
    ~PipeData();

  public:
    Plazza::PipeData::Data const&	getData() const;
    std::string	const&	getString() const;
    DataType const&	getDataType() const;
    Command::Information const&	getInformation() const;

  public:
    void	setString(const std::string&);
    void	setDataType(DataType const&);
    void	setInformation(Command::Information const&);

  private:
    Data	_data;
    std::string	_str;
  };
}

#endif /* !APIPEDATA_HH_ */
