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

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void announce(void);
		void addName(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);


#endif