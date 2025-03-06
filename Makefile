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

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRCDIR := src
CHKDIR := check
OPSDIR := operations
OBJDIR := obj
LIBFTDIR := libft
FTPRINTFDIR := ft_printf
INCLUDEDIR := include

SRCS := $(wildcard $(SRCDIR)/*.c) $(wildcard $(CHKDIR)/*.c) $(wildcard $(OPSDIR)/*.c)
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

NAME := push_swap

LIBFT := $(LIBFTDIR)/libft.a
FTPRINTF := $(FTPRINTFDIR)/libftprintf.a
LIBS := -L	$(LIBFTDIR)	-lft	-L	$(FTPRINTFDIR)	-lftprintf
INCLUDES :=	-I	$(INCLUDEDIR)	-I	$(LIBFTDIR)	-I	$(FTPRINTFDIR)

$(NAME):	$(LIBFT)	$(FTPRINTF)	$(OBJS)
			$(CC)	$(CFLAGS)	$(OBJS)	$(LIBS)	-o	$(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir	-p	$(dir $@)
	$(CC)	$(CFLAGS)	$(INCLUDES)	-c	$<	-o	$@

$(OBJDIR):
	mkdir	-p	$(OBJDIR)	$(OBJDIR)/src	$(OBJDIR)/check	$(OBJDIR)/operations

$(LIBFT):
	@make	-C	$(LIBFTDIR)

$(FTPRINTF):
	@make	-C	$(FTPRINTFDIR)

clean:
	rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(FTPRINTFDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(FTPRINTFDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re