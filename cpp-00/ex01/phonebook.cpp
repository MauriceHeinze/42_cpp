//
// Created by Maurice Heinze on 1/7/23.
//

#include "./phonebook.hpp"

void	Phonebook::addContact(void)
{
	int		i;
	Contact	entry;

	i = 7;
	while (i)
	{
		book[i] = book[i - 1];
		i--;
	}
	std::cout << "First name:	";
	entry.setFirstName(get_input());
	std::cout << "Last name:	";
	entry.setLastName(get_input());
	std::cout << "Nickname:	";
	entry.setNickname(get_input());
	std::cout << "Phone number:	";
	entry.setPhoneNumber(get_input_phone());
	std::cout << "Darkest secret:	";
	entry.setDarkestSecret(get_input());
	std::cout << "New contact saved! ✅\n";
	book[0] = entry;
}

int		Phonebook::findContact(int index)
{
	Contact	entry = book[index];

	if (entry.getFirstName().length() == 0)
		return (0);
	else
		return (1);
}

void	Phonebook::displayContactDetails(int index)
{
	Contact	entry = book[index];
	std::cout << "First name:	" << entry.getFirstName() << "\n";
	std::cout << "Last name:	" << entry.getLastName() << "\n";
	std::cout << "Nickname:	" << entry.getNickname() << "\n";
	std::cout << "Phone number:	" << entry.getPhoneNumber() << "\n";
	std::cout << "Darkest secret:	" << entry.getDarkestSecret() << "\n";
}

void	Phonebook::displayContactBasics(int index)
{
	std::string tmp;
	Contact entry = book[index];

	tmp = entry.getFirstName();
	if (tmp.length() == 0)
		return ;
	tmp.resize(10, ' ');
	std::cout << tmp << " | ";
	tmp = entry.getLastName();
	tmp.resize(10, ' ');
	std::cout <<  tmp << " | ";
	tmp = entry.getNickname();
	tmp.resize(10, ' ');
	std::cout <<  tmp << " | ";
	std::cout << std::to_string(index + 1) << "\n";
}

void	Phonebook::searchContacts()
{
	std::string	index;
	int	i_index = -1;
	int	i = 0;

	std::cout << "\033[32m" << "First name" << "\033[0m" << " | ";
	std::cout << "\033[33m" << "Last name" << "\033[0m" << "  | ";
	std::cout << "\033[34m" << "Nickname" << "\033[0m" << "   | ";
	std::cout << "\033[35m" << "Index" << "\033[0m" << "\n";
	std::cout << "************************************************" << "\n";
	while (i < 8)
		displayContactBasics(i++);
	std::cout << "Please enter the index of the contact: ";
	while (i_index < 0)
	{
		std::getline(std::cin, index);
		i_index = string_to_int(index);
		while (i_index < 1 || i_index > 8)
		{
			std::cout << "\033[31m" << "Please enter number between 1 or 8!\n" << "\033[0m" << "Please enter the index of the contact: ";
			std::getline(std::cin, index);
			i_index = string_to_int(index);
		}
		if (findContact(i_index - 1) == 0)
		{
			std::cout << "\033[31m" << "Contact doesn't exist!\n" << "\033[0m" << "Please enter the index of an existing contact: ";
			i_index = -1;
		}
	}
	displayContactDetails(string_to_int(index) - 1);
}

int	Phonebook::string_to_int(std::string buffer)
{
	int i = 0;
	int result = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
			result = result * 10 + (buffer[i] - '0');
		else
			return (-1);
		i++;
	}
	return (result);
}