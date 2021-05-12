NAME = bbbbbb.a

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putstr.c utils.c main.c libft.a
#OBJ = $(SRC.c=.o)
all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
clean :
	/bin/rm -f *.o
	rm -f $(NAME)
fclean :
	/bin/rm -f $(NAME)
re : fclean all