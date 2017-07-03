# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/02 12:01:32 by jle-quel          #+#    #+#              #
#    Updated: 2017/06/28 19:14:45 by jle-quel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS += -Wall -Wextra -Werror -I includes

SRC =   ./sources/main.c \
        ./sources/ft_cd.c \
        ./sources/ft_display_tools.c \
        ./sources/ft_echo.c \
        ./sources/ft_env_tools.c \
        ./sources/ft_setenv.c \
		./sources/ft_split.c \
        ./sources/ft_tools.c \
        ./sources/ft_unsetenv.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(FLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
