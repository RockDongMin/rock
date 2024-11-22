# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rockdongmin <marvin@42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 16:55:53 by rockdongmin       #+#    #+#              #
#    Updated: 2024/11/21 19:46:28 by dongmpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFTFILE = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR)

RM = rm -rf
AR = ar crs

SRCS = ft_printf.c ft_put.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(AR) $(NAME) $(OBJS) $(LIBFTDIR)/$(LIBFTFILE)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
