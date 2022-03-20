# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 22:54:05 by emadriga          #+#    #+#              #
#    Updated: 2021/09/05 22:54:06 by emadriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

CLIENT	=	client
SERVER	=	server

SRC_C	=	client.c 
SRC_S	=	server.c

CC 		= gcc
RM 		= rm -f

FLAGS	= -Wall -Wextra -Werror

OBJS_S	= $(SRC_S:.c=.o)
OBJS_C	= $(SRC_C:.c=.o)


.c.o:
			$(CC) $(FLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJS_C)
			$(CC) $(FLAGS) -o $(CLIENT) $(OBJS_C)

$(SERVER):	$(OBJS_S)
			$(CC) $(FLAGS) -o $(SERVER) $(OBJS_S)

clean:
		$(RM) $(OBJS_S) $(OBJS_C) 

fclean:	clean
		$(RM) $(NAME) $(CLIENT) $(SERVER)

re:		fclean all

.PHONY:	all clean fclean re
