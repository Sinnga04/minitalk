NAME = libftprintf.a

SRCS =	ft_printf_utilis2.c ft_printf_utils.c ft_printf.c 
 
OBJS = $(SRCS:.c=.o)
CFLAGS = -c -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all