# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 05:48:46 by nsavry            #+#    #+#              #
#    Updated: 2014/01/26 13:09:38 by nsavry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FTC = main.c\
	  ft_current_solve.c\
	  ft_current_read.c\
	  ft_current_check.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	Make -C ./libft
	gcc -o $(NAME) -L./libft -lft $(FTO)

%.o: %.c
	gcc -Wall -Werror -Wextra -I./ -I./libft/includes -c $<

clean:
	make -C ./libft clean
	rm -rf $(FTO)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
