//
// ThreadTask.hh for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Tue Apr 18 20:02:14 2017 Arnaud WURMEL
// Last update Wed Apr 19 20:46:59 2017 Arnaud WURMEL
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
    ThreadTask(std::string const&, Command::Information const&);
    ~ThreadTask();

  public:
    TaskState const&	getTaskState() const;
    Command::Information const&	getResearch() const;
    std::string const&	getFilePath() const;
    std::vector<std::string> const&	getResult() const;

  public:
    void	setTaskState(TaskState const&);
    void	setResult(std::vector<std::string> const&);

  private:
    TaskState	_state;
    std::string	_file;
    

  private:
    std::vector<std::string>	_result;
    Command::Information	_research;
  };
}

#endif /* !THREADTASK_HH_ */
