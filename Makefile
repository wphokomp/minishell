# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 11:16:25 by wphokomp          #+#    #+#              #
#    Updated: 2017/09/18 14:10:33 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/cmds.c src/memory.c src/main.c src/env.c lib/libft.a

FLAGS = clang -Werror -Wextra -Wall -g -I includes -o

all: $(NAME)

$(NAME):
	@make -C lib/ fclean && make -C lib/ all
	@$(FLAGS) $(NAME) $(SRC)

clean:
	@make -C lib/ clean
	@rm -fr minishell.dSYM

fclean: clean
	@make -C lib/ fclean
	@rm -f $(NAME)

re: fclean all
