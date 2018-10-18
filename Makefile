SRC =	ressources/Weapon.cpp \
	ressources/StealthBox.cpp \
	ressources/Gun.cpp \
	ressources/Bomb.cpp \
	ressources/MetalGear.cpp \
	ressources/WeaponInventory.cpp \
	ressources/Compte.cpp \
	ressources/Transaction.cpp \
	ressources/Log.cpp \
	ressources/main.cpp \

OBJ = $(SRC:%.cpp=%.o)

NAME = drebirshop

CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14

RM = rm -f

all: $(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
