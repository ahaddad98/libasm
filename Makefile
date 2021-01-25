# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 19:18:51 by ahaddad           #+#    #+#              #
#    Updated: 2021/01/25 19:18:53 by ahaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libasm.a
SRC_NAME=ft_strlen.s\
        ft_strcpy.s\
        ft_strcmp.s\
        ft_write.s\
        ft_read.s\
		ft_strdup.s\


OBJ_NAME= $(SRC_NAME:.s=.o)
FLAGS= -fmacho64
COMP= nasm
all: $(NAME)
$(NAME) : $(OBJ_NAME)
	ar rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)
%.o: %.s
	$(COMP) $(FLAGS) $<
clean:
	@rm -rf $(OBJ_NAME)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m"
fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31m>> $(NAME) && all obbjects are deleted.\033[0m"
re : fclean all
