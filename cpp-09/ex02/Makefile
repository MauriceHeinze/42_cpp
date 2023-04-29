NAME		= 	PmergeMe
CC 			= 	c++
CPPFLAGS	= 	-Wall -Wextra -Werror -std=c++98
SRC 		=	main.cpp		\
				PmergeMe.cpp

OBJ = $(SRC:%.cpp=%.o)
all: $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all