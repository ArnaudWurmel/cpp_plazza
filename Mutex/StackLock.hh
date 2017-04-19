//
// StackLock.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Apr 19 12:57:09 2017 Arnaud WURMEL
// Last update Wed Apr 19 13:01:27 2017 Arnaud WURMEL
//

#ifndef STACKLOCK_HH_
# define STACKLOCK_HH_

# include <mutex>

namespace	Plazza
{
  class		StackLock
  {
  public:
    StackLock(std::mutex&);
    ~StackLock();

  private:
    StackLock(StackLock&);
    StackLock&	operator=(StackLock const&);

  private:
    std::mutex&	_mutex;
  };
}

#endif /* !STACKLOCK_HH_ */
