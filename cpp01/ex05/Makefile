NAME	:= harl
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror

SRC		:=	main.cpp \
			Harl.cpp

OBJ		:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re