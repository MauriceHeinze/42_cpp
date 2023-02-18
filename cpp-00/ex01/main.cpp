//
// Created by Maurice Heinze on 1/7/23.
//

#include "./phonebook.hpp"

int main(void)
{
	Phonebook book;
	std::string	command;

	std::cout << "✨ WELCOME TO THE" << "\033[33m AWESOME \033[0m" << "\033[34mPHONEBOOK\033[0m! ✨\n\n";
	std::cout << "Enter either ADD, SEARCH or EXIT.\n";
	while (1)
	{
		std::cout << "\033[32m" << "Your command: " << "\033[0m";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			book.addContact();
		else if (command.compare("SEARCH") == 0)
		{
			if (book.findContact(0))
				book.searchContacts();
			else
				std::cout << "\033[31m" << "No contacts available! " << "\033[0m" << "Use ADD to add a contact or EXIT to exit the program.\n";
		}
		else if (command.compare("EXIT") == 0 || cin.eof())
			break ;
		else
			std::cout << "\033[31m" << "Invalid command! " << "\033[0m" << "Enter either ADD, SEARCH or EXIT.\n";
	}
	return 0;
}