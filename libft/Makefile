# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 09:11:48 by jle-quel          #+#    #+#              #
#    Updated: 2017/07/02 20:20:02 by jle-quel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_intlen.c ft_isalnum.c ft_isalpha.c ft_toupper.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_pimplen.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	  ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	  ft_countwords.c ft_lstnew.c ft_lstiter.c ft_lstdel.c ft_lstadd.c \
	  ft_lstdelone.c ft_lstmap.c ft_lstlen.c ft_lstaddend.c ft_lstmalloc.c ft_lstprint.c \
	  ft_lstdelnode.c ft_printarray.c ft_arraylen.c get_next_line.c \
	  ft_threejoin.c ft_arraydel.c ft_listdel.c ft_populate_list.c ft_atoi_mod.c

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -c $(SRC) -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@/bin/rm -Rf $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
