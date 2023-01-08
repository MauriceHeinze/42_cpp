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

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

using namespace std;

std::string	get_input();
std::string	get_input_phone();

class Phonebook
{
	private:
		Contact book[8];
	public:
		void	addContact(void);
		int		findContact(int index);
		void	displayContactDetails(int index);
		void	displayContactBasics(int index);
		void	searchContacts(void);
		int		string_to_int(std::string);
};

#endif