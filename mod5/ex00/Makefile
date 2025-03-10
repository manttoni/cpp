NAME = bureaucrat

SRC = Bureaucrat.cpp \
      main.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
