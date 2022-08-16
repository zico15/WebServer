# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 21:46:08 by edos-san          #+#    #+#              #
#    Updated: 2022/08/15 22:49:11 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			=  c++
CFLAGS 		=  -Wall -Wextra -Werror -std=c++98
RM			= 	/bin/rm -f
NAME		= 	websserv
SRCS		= 	main.cpp \
				./src/server/Server.cpp \
				./src/client/Client.cpp \
				./src/socket/Socket.cpp

OBJS		= 	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		 $(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

m: fclean

v:
	@make re && make clean && clear && valgrind --leak-check=full --log-file="logfile.out" -v ./$(NAME):
e:
	@make re && make clean && clear && valgrind --leak-check=full --track-origins=yes ./$(NAME):
r:
	@make re && make clean && clear && ./$(NAME)

.PHONY: all re clean fclean m