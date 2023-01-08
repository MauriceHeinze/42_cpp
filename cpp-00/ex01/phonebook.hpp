/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   phonebook.hpp									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mheinze <mheinze@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/12/13 19:04:23 by ncolomer		  #+#	#+#			 */
/*   Updated: 2023/01/07 17:26:33 by mheinze		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
using namespace std;

std::string	get_input()
{
	int			i;
	int			char_found;
	std::string	input;

	i = 0;
	char_found = 0;
	std::getline(std::cin, input);
	while (input[i] && (char_found == 0))
	{
		if (input[i] > 32 && input[i++] < 127)
			char_found = 1;
	}
	if (char_found == 0)
	{
		std::cout << "\033[31m" << "Error! " << "\033[0m" << "Please enter something: ";
		return (get_input());
	}

	return (input);
}

std::string	get_input_phone()
{
	int			i;
	int			non_digit;
	std::string	input;

	i = 0;
	non_digit = 0;
	std::getline(std::cin, input);
	while (input[i] && (non_digit == 0))
	{
		if (input[i] < 47 || input[i++] > 58)
			non_digit = 1;
	}
	if (input.length() == 0)
	{
		std::cout << "\033[31m" << "Error! " << "\033[0m" << "Please enter a phone number: ";
		return (get_input_phone());
	}
	else if (non_digit == 1)
	{
		std::cout << "\033[31m" << "Error! " << "\033[0m" << "Please enter digits only: ";
		return (get_input_phone());
	}

	return (input);
}

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void setFirstName(std::string str) {
			firstName = str;
		}
		void setLastName(std::string str) {
			lastName = str;
		}
		void setNickname(std::string str) {
			nickname = str;
		}
		void setPhoneNumber(std::string str) {
			phoneNumber = str;
		}
		void setDarkestSecret(std::string str) {
			darkestSecret = str;
		}
		std::string	getFirstName() {
			return (firstName);
		}
		std::string	getLastName() {
			return (lastName);
		}
		std::string	getNickname() {
			return (nickname);
		}
		std::string	getPhoneNumber() {
			return (phoneNumber);
		}
		std::string	getDarkestSecret() {
			return (darkestSecret);
		}
};

class Phonebook
{
	private:
		Contact book[8];
	public:
		void	addContact(void)
		{
			int		i;
			Contact	entry;
			Contact	tmp_entry;

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
		int		findContact(int index)
		{
			Contact	entry = book[index];

			if (entry.getFirstName().length() == 0)
				return (0);
			else
				return (1);
		}
		void	displayContactDetails(int index)
		{
			Contact	entry = book[index];
			std::cout << "First name:	" << entry.getFirstName() << "\n";
			std::cout << "Last name:	" << entry.getLastName() << "\n";
			std::cout << "Nickname:	" << entry.getNickname() << "\n";
			std::cout << "Phone number:	" << entry.getPhoneNumber() << "\n";
			std::cout << "Darkest secret:	" << entry.getDarkestSecret() << "\n";
		}
		void	displayContactBasics(int index)
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
		int	string_to_int(std::string buffer)
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
		void	searchContacts()
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
};

#endif