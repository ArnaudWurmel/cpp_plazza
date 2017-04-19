//
// ThreadTask.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 18 20:02:14 2017 Arnaud WURMEL
// Last update Tue Apr 18 20:12:05 2017 Arnaud WURMEL
//

#ifndef THREADTASK_HH_
# define THREADTASK_HH_

namespace	Plazza
{
  class	ThreadTask
  {
  public:
    enum	TaskState
      {
	NotStarted = 0,
	InProgress,
	Success,
	Failure
      };

  public:
    ThreadTask(std::string const&);
    ~ThreadTask();

  public:
    TaskState const&	getTaskState() const;
    std::string const&	getFilePath() const;

  public:
    void	setTaskState(TaskState const&);

  private:
    TaskState	_state;
    std::string	_file;
  };
}

#endif /* !THREADTASK_HH_ */
