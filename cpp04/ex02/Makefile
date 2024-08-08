NAME = animal
COMPILER = c++
FLAGS = -Wall -Wextra -Werror

SRC =	main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re