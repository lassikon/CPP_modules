NAME	:= bsp
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror

SRC		:=	main.cpp \
			Fixed.cpp \
			Point.cpp \
			bsp.cpp

OBJ		:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re