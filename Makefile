##
## Makefile for cpp_plazza in /home/wurmel_a/rendu/cpp_plazza
## 
## Made by Arnaud WURMEL
## Login   <wurmel_a@epitech.net>
## 
## Started on  Mon Apr 10 10:30:16 2017 Arnaud WURMEL
## Last update Mon Apr 10 12:41:27 2017 Arnaud WURMEL
##

CC		=	g++
RM		=	rm -f

SRCS		=	Plazza/Plazza.cpp \
			Errors/Errors.cpp

OBJS		=	$(SRCS:.cpp=.o)


ECHO		=	/bin/echo -e
ERROUTPUT	=	2>/dev/null

TITLE		=	"CPP_PLAZZA 2020"
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"



CXXFLAGS	+= 	-Wall -Wextra -std=c++14

NAME		=	plazza

all:			$(NAME)

$(NAME):		title $(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(ERROUTPUT) &&		\
			 $(ECHO) $(TEAL)"[OK]" $(GREEN) $(NAME) $(DEFAULT) ||	\
			 $(ECHO) $(RED)"[KO]" $(NAME) $(DEFAULT)

.cpp.o:
			@$(CC) -c $< -o $@ &&					\
			 $(ECHO) $(TEAL)"[OK]" $(GREEN) $< $(DEFAULT) ||	\
			 $(ECHO) $(RED)"[KO]" $< $(DEFAULT)

title:
			@$(ECHO) $(TEAL) $(TITLE) $(DEFAULT)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
