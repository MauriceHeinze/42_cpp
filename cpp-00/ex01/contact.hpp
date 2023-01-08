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

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact();
		~Contact();
		void setFirstName(std::string str);
		void setLastName(std::string str);
		void setNickname(std::string str);
		void setPhoneNumber(std::string str);
		void setDarkestSecret(std::string str);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
};

#endif