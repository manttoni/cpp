### BINARIES ###
NAME = span

### SOURCES AND OBJECTS ###
SRC =	main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)

### COMPILER AND FLAGS ###
CC = c++
FLAGS = -Wall -Wextra -Werror

### EXECUTABLE AND OBJECTS CREATION ###
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

### PHONY TARGETS ###
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
