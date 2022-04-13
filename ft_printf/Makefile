# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: a******n <a******n@student.42yerevan.am>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 09:05:37 by tumolabs          #+#    #+#              #
#    Updated: 2022/03/15 09:05:50 by tumolabs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		= ft_printf ft_printf_handlers ft_printf_utils
NAME		= libftprintf.a
INCLUDE		= includes
SRCDIR		= src/
OBJDIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar crs
SRC 		= 	$(addprefix $(SRCDIR), $(addsuffix .c, $(SOURCES)))
OBJ 		= 	$(addprefix $(OBJDIR), $(addsuffix .o, $(SOURCES)))


all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

$(OBJDIR)%.o: $(SRCDIR)%.c
			@mkdir -p $(OBJDIR)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@$(RM) -rf $(OBJDIR)

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
