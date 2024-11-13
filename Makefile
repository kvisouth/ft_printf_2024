SRC		= src/ft_printf.c src/ft_printf_utils.c
NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
AR		= ar rcs

OBJ		= $(SRC:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
