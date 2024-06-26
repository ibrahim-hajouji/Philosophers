NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror 
SRC = ./philo.c \
		./error.c \
		./utils.c \
		./parsing.c \
		./forks.c \
		./actions.c \
		./routine.c \
		./check.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./philo.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re 