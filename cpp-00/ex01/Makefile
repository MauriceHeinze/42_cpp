# Folders and Names
NAME		= phonebook
SRCSDIR		= .
OBJSDIR		= objs
INCLUDES	= .

SRCS		=	phonebook.cpp, phonebook.hpp

# Compiler options
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################

all: $(NAME)

$(NAME): $(SRCSDIR)/$(SRCS)
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $^

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

