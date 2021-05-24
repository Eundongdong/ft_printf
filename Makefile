
NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a
RM = rm -rf
CC = gcc
AR = ar
AFLAGS = rcs
#CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	   utils.c \
	   ft_putstr.c
OBJECTS = $(SRCS:.c=.o)
all : $(NAME)
clean :
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT)
fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
re : fclean all

$(NAME) : $(OBJECTS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(AFLAGS) $@ $?
bonus : all
.PHONY : all clean fclean re bonus