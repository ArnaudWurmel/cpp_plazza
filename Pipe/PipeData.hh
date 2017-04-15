//
// PipeData.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 11 20:16:58 2017 Arnaud WURMEL
// Last update Sat Apr 15 22:19:22 2017 Arnaud WURMEL
//

#ifndef APIPEDATA_HH_
# define APIPEDATA_HH_

# define MAX_DATA 1024

namespace	Plazza
{
  template<typename T>
  class	PipeData
  {
  public:
    enum	DataType : int
      {
	FAILURE = -1,
	UNUSED = 0,
	GET_PROCESS_INFO,
	SEND_DATA,
	ASSIGN_ORDER
      };
    
  public:
    struct			Data
    {
      DataType			_type;
      T				_stockage;
    };

  public:
    PipeData<T>(DataType const& type)
    {
      _data._type = type;
    }
    PipeData<T>()
    {

    }
    ~PipeData<T>() {}

  public:
    Plazza::PipeData<T>::Data const&	getData() const
    {
      return _data;
    }
    
    T const&	getStockage() const
    {
      return _data._stockage;
    }

    DataType const&	getDataType() const
    {
      return _data._type;
    }

  public:
    void	setStockage(T const& stockage)
    {
      _data._stockage = stockage;
    }

    void	setDataType(DataType const& type)
    {
      _data._type = type;
    }

  private:
    Data	_data;
  };
}

#endif /* !APIPEDATA_HH_ */
