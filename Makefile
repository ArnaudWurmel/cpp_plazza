##
## Makefile for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
## 
## Made by Arnaud WURMEL
## Login   <wurmel_a@epitech.net>
## 
## Started on  Mon Apr 10 10:30:16 2017 Arnaud WURMEL
## Last update Thu Apr 27 10:35:04 2017 Arnaud WURMEL
##


CC		=	g++
RM		=	rm -f

SRCS		=	Plazza/Plazza.cpp \
			Errors/Errors.cpp \
			Errors/ProcessError.cpp \
			Process/Process.cpp \
			Parser/Parser.cpp \
			Parser/Command.cpp \
			Pipe/Pipe.cpp \
			Pipe/PipeData.cpp \
			Thread/ThreadPool.cpp \
			Thread/Thread.cpp \
			Thread/ThreadTask.cpp \
			Mutex/StackLock.cpp \
			Searcher/Searcher.cpp \
			UIManager/UIManager.cpp \
			Logger/Logger.cpp \
			srcs/main.cpp \

OBJS		=	$(SRCS:.cpp=.o)


ECHO		=	/bin/echo -e
ERROUTPUT	=	2>/dev/null
ERREXIT		=	exit 1

TITLE		=	"CPP_PLAZZA 2020"
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

HEADERS		+=	-I ./Plazza \
			-I ./Errors \
			-I ./Process \
			-I ./Parser \
			-I ./Abstract \
			-I ./Pipe \
			-I ./Mutex \
			-I ./Searcher \
			-I ./Logger \
			-I ./Thread

LDFLAGS		=	-lpthread

CXXFLAGS	+= 	-Wall -Wextra -std=c++14

NAME		=	plazza

all:			$(NAME)

$(NAME):		title $(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) &&			\
			 $(ECHO) $(TEAL)"[OK]" $(GREEN) $(NAME) $(DEFAULT) ||	\
			 $(ECHO) $(RED)"[KO]" $(NAME) $(DEFAULT)

ui:			CXXFLAGS += -DUIMODE
ui:			LDFLAGS +=  -lsfml-graphics -lsfml-window -lsfml-system
ui:			HEADERS	+= -I ./UIManager
ui:			$(OBJS) $ $(NAME)
			make -C uimode/

.cpp.o:
			@$(CC) -c $< -o $@ $(HEADERS) $(CXXFLAGS) &&		\
			 $(ECHO) $(TEAL)"[OK]" $(GREEN) $< $(DEFAULT) ||	\
			 ($(ECHO) $(RED)"[KO]" $< $(DEFAULT) && $(ERREXIT))

title:
			@$(ECHO) $(TEAL) $(TITLE) $(DEFAULT)

clean:
			$(RM) $(OBJS)
			$(RM) -f uimode/*.o

fclean:			clean
			$(RM) $(NAME)
			$(RM) uimode/cpp_$(NAME)

re:			fclean all
