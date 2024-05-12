NAME = markdown_fmt
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -O0

SRCS = create_cell.c printf_markdown.c utils.c main.c
OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(DEBUGFLAGS) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(DEBUGFLAGS) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re valgrind

