# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 21:46:08 by edos-san          #+#    #+#              #
#    Updated: 2022/08/17 22:46:26 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

CC = c++ -std=c++98 -pedantic -fsanitize=address -g

SRCS =	$(shell find . -name '*.cpp')
OBJS = $(addsuffix .o, $(basename $(SRCS)))
INCLUDES = $(addprefix -I, $(shell find headers -type d))

all: $(NAME)

$(NAME):
	$(CC) $(INCLUDES) $(SRCS) -o $@ $<

clean:
	rm -rf $(NAME)

re: clean all

r:
	make && clear && ./$(NAME)

.PHONY: all clean re
