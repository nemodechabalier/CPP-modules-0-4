# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

# Fichiers sources et objets
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = ClapTrap

# Règles
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re