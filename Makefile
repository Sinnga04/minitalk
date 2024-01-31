CLIENT := client
SERVER := server

SRC_C = client.c libs.c
SRC_S = server.c 

OBJ_C = $(SRC_C:%.c=%.o)
OBJ_S = $(SRC_S:%.c=%.o)


CFLAGS := -Wall -Wextra -Werror
CC := gcc

LIBFTPRINTF_PATH := ./ft_printf/
LIBFTPRINTF_NAME := libftprintf.a
LIBFTPRINTF := $(LIBFTPRINTF_PATH)$(LIBFTPRINTF_NAME)

.PHONY: all clean fclean re

all: $(CLIENT) $(SERVER)

$(LIBFTPRINTF):
	@make -C $(LIBFTPRINTF_PATH)

$(OBJ_C): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_S): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_L): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT): $(OBJ_C) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_C)  $(LIBFTPRINTF) -o $(CLIENT)

$(SERVER): $(OBJ_S) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_S) $(LIBFTPRINTF) -o $(SERVER)

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	rm -f *.o

fclean: clean
	@make -C $(LIBFTPRINTF_PATH) fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all