//
// Created by Maurice Heinze on 1/7/23.
//

#include "contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string str) {
	firstName = str;
}
void	Contact::setLastName(std::string str) {
	lastName = str;
}
void	Contact::setNickname(std::string str) {
	nickname = str;
}
void	Contact::setPhoneNumber(std::string str) {
	phoneNumber = str;
}
void	Contact::setDarkestSecret(std::string str) {
	darkestSecret = str;
}
std::string	Contact::getFirstName() {
	return (firstName);
}
std::string	Contact::getLastName() {
	return (lastName);
}
std::string	Contact::getNickname() {
	return (nickname);
}
std::string	Contact::getPhoneNumber() {
	return (phoneNumber);
}
std::string	Contact::getDarkestSecret() {
	return (darkestSecret);
}