# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 15:39:10 by halzamma          #+#    #+#              #
#    Updated: 2025/03/05 15:39:10 by halzamma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRCDIR := src
OBJDIR := obj
LIBFTDIR := libft
FTPRINTF_DIR := ft_printf_src

SRCS := $(wildcard $(SRCDIR)/*.c) $(wildcard operations/*.c)
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFT := $(LIBFTDIR)/libft.a
FTPRINTF := $(FTPRINTF_DIR)/libftprintf.a
LIBS := -L $(LIBFTDIR) -lft -L $(FTPRINTF_DIR) -lftprintf
INCLUDES := -I include -I $(LIBFTDIR) -I $(FTPRINTF_DIR)

$(NAME): $(LIBFT) $(FTPRINTF) $(OBJS)
 $(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
 $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
 mkdir -p $(OBJDIR) $(OBJDIR)/operations

$(LIBFT):
 make -C $(LIBFTDIR)

$(FTPRINTF):
 make -C $(FTPRINTF_DIR)

clean:
 rm -rf $(OBJDIR)
 make -C $(LIBFTDIR) clean
 make -C $(FTPRINTF_DIR) clean

fclean: clean
 rm -f $(NAME)
 make -C $(LIBFTDIR) fclean
 make -C $(FTPRINTF_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re