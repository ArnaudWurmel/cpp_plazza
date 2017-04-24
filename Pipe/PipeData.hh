//
// PipeData.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 20:16:58 2017 Arnaud WURMEL
// Last update Mon Apr 24 22:38:27 2017 Arnaud WURMEL
//

#ifndef APIPEDATA_HH_
# define APIPEDATA_HH_

# define MAX_SIZE 255

namespace	Plazza
{
  class	PipeData
  {
  public:
    enum	DataType : int
      {
	FAILURE = -1,
	UNUSED = 0,
	GET_PROCESS_INFO,
	GET_FREE_SPACE,
	GET_ORDER_STATE,
	GET_PROCESS_END,
	SEND_DATA,
	ASSIGN_ORDER
      };
    
  public:
    union	DataStockage
    {
      int32_t	integer;
      char	string[MAX_SIZE];
    };
  public:
    struct			Data
    {
      DataType			_type;
      DataStockage		_stockage;
    };

  public:
    PipeData(DataType const& type);
    PipeData();
    ~PipeData();

  public:
    Data const&		getData() const;
    DataType const&	getDataType() const;

  public:
    void	setInteger(uint32_t value);
    void	setString(std::string const&);
    void	setDataType(DataType const& type);
    void	setStockage(DataStockage const&);


  private:
    Data	_data;
  };
}

#endif /* !APIPEDATA_HH_ */
