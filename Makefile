NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
$(NAME): $(NAME).o $(NAME_BONUS).o
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).o
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(NAME_BONUS).o

$(NAME).o: $(NAME).c
	$(CC) $(CFLAGS) -c $(NAME).c

$(NAME_BONUS).o: $(NAME_BONUS).c
	$(CC) $(CFLAGS) -c $(NAME_BONUS).c

