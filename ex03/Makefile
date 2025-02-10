COMPILER = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = a.out

SRC = Fixed.cpp Point.cpp bsp.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -o $@ -c $<

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re