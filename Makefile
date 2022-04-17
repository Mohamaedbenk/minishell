# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnamir <tnamir@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 16:38:27 by tnamir            #+#    #+#              #
#    Updated: 2022/04/17 22:46:52 by tnamir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#								  -*-Makefile-*-							   #

HEADER = minishell.h

FLAGS = -L/Users/tnamir/.brew/opt/readline/lib -I/Users/tnamir/.brew/opt/readline/include -lreadline

SRC = main.c ./files/execute.c ./files/f_or_d.c ./files/sp_remover.c ./files/quotes_handler.c ./files/builtins_cmds.c \
 ./files/utils.c ./files/env_var.c ./files/cpy.c ./files/export.c ./files/unset.c ./files/pipes.c ./files/redirections.c \
 ./files/metacharacters.c ./files/conditions.c ./files/utils2.c

NAME = minishell

LIBFT = ./libft/libft.a

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADER)
	@cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	@cc $(FLAGS) $(RL_FLAG) -c -o $@ $<

$(LIBFT) :
	@$(MAKE) -C ./libft

clean :
	@rm -rf ./libft/*.o $(OBJS)

fclean : clean
	@rm -rf $(LIBFT) $(NAME)

re : fclean all

.PHONY : clean fclean re

#								  -*-Makefile-*-							   #