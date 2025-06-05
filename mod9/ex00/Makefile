### BINARIES ###
NAME = btc

### SOURCES AND OBJECTS ###
SRC =	main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

### COMPILER AND FLAGS ###
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

### EXECUTABLE AND OBJECTS CREATION ###
$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

### PHONY TARGETS ###
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
