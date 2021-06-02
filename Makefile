
NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a
RM = rm -rf
CC = gcc
AR = ar
AFLAGS = rcs
#CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c utils.c ft_print_int.c ft_form_info.c ft_putstr.c ft_print_char.c ft_print_percent.c \
	   ft_print_string.c \
	   ft_print_u_int.c \
	   ft_print_base.c \
	   ft_print_address.c ft_form_info_2.c ft_print_utils.c
	   
OBJECTS = $(SRCS:.c=.o)
all : $(NAME)
clean :
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT)
fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)
re : fclean all

$(NAME) : $(OBJECTS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(AFLAGS) $@ $?
bonus : all
.PHONY : all clean fclean re bonus