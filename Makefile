CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft

TARGET = a.out

SRCS = ft_printf.c ft_put.c $(wildcard libft/*.c)

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
