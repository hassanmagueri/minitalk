# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 21:13:40 by emagueri          #+#    #+#              #
#    Updated: 2024/02/16 16:03:57 by emagueri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRC			= 	mandatory/server.c \
						utils/ft_putchar_fd.c \
						utils/ft_putstr_fd.c \
						utils/ft_putendl_fd.c \
						utils/my.c \
						utils/ft_putnbr_fd.c \
						utils/ft_atoi.c

CLIENT_SRC			=	mandatory/client.c \
						utils/ft_putchar_fd.c \
						utils/ft_putstr_fd.c \
						utils/ft_putendl_fd.c \
						utils/my.c \
						utils/ft_putnbr_fd.c \
						utils/ft_isdigit.c \
						utils/ft_atoi.c

NAME_SRC_BONUS		= 	bonus/server.c \
						utils/ft_putchar_fd.c \
						utils/ft_putstr_fd.c \
						utils/ft_putendl_fd.c \
						utils/my.c \
						utils/ft_putnbr_fd.c \
						utils/ft_atoi.c

CLIENT_SRC_BONUS	=	bonus/client.c \
						utils/ft_putchar_fd.c \
						utils/ft_putstr_fd.c \
						utils/ft_putendl_fd.c \
						utils/my.c \
						utils/ft_putnbr_fd.c \
						utils/ft_isdigit.c \
						utils/ft_atoi.c

NAME = server 
CLIENT = client 

NAME_BONUS = server_bonus
CLIENT_BONUS = client_bonus 

NAME_OBJ		=	$(NAME_SRC:.c=.o)
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

NAME_OBJ_BONUS			=	$(NAME_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS		=	$(CLIENT_SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:$(NAME) $(CLIENT)

bonus:$(NAME_BONUS) $(CLIENT_BONUS)

$(NAME): $(NAME_OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_BONUS): $(NAME_OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $@
	
$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME_OBJ)
	$(RM) $(CLIENT_OBJ)
	$(RM) $(NAME_OBJ_BONUS)
	$(RM) $(CLIENT_OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CLIENT)
	$(RM) $(NAME_BONUS)
	$(RM) $(CLIENT_BONUS)

re: fclean all

.PHONY: clean