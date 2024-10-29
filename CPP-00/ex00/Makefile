# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = megaphone
SRC = megaphone.cpp

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)

# Règle pour nettoyer les fichiers de compilation
fclean: clean

# Règle pour nettoyer et recompiler
re: fclean all

.PHONY: all clean fclean re
