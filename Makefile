NAME 				= so_long
SRCS 				= main.c parsing.c
CFLAGS	 			= -Wall -Werror -Wextra
OBJS        		= $(SRCS:.c=.o)
CC = cc

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re