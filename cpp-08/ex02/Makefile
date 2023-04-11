NAME		= 	MutantStack
CC 			= 	c++
CPPFLAGS	= 	-Wall -Wextra -Werror -std=c++98
SRC 		=	main.cpp
HEADER		=	MutantStack.hpp

OBJ = $(SRC:%.cpp=%.o)
all: $(NAME)
$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all