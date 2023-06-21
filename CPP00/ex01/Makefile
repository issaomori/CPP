NAME = Phonebook

CFLAGS =  -Wall -Wextra -Werror
CC = c++
SRCS = main.cpp\
	   Phonebook.cpp\
	   Contact.cpp

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
