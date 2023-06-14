NAME = megaphone

CFLAGS =  -Wall -Wextra -Werror
CC = c++

SRCS = megaphone.cpp

OBJS = ${SRCS:.cpp=.o}
all:        $(NAME)

$(NAME):    $(OBJS)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re