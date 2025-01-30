# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

# Fichiers sources et objets
SRC = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = zombie

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
