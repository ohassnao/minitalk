SERVER	= server

CLIENT	= client

ATOI 	= atoi 

SRC_C	= client.c

SRC_S	= server.c

SRC_A	= atoi.c

OBJ_C	= client.o

OBJ_S	= server.o

OBJ_A	= atoi.o

HEADER	= minitalk.h 

CC		= cc

FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all: $(SERVER) $(CLIENT)

$(NAME) : all

$(SERVER)	:	$(OBJ_S) $(OBJ_A) $(HEADER)
			$(CC) $(FLAGS) -o $@ $(OBJ_S) $(OBJ_A)

$(CLIENT)	:	$(OBJ_C) $(OBJ_A) $(HEADER)
			$(CC) $(FLAGS) -o $@ $(OBJ_C) $(OBJ_A)

%.o	:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean	:
		$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_A)
    
fclean	:	clean
		$(RM) $(SERVER) $(CLIENT) $(ATOI)

re	:	fclean all

.PHONY	:	all clean fclean re