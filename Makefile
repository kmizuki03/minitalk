NAME = client server
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME)

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o client $(OBJ_CLIENT)

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o server $(OBJ_SERVER)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
