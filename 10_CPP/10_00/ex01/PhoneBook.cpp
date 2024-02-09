/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:14:23 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/07 18:03:59 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){ }

PhoneBook::~PhoneBook(void){ }

void PhoneBook::addContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (_contact[0].getFirstName().empty())
		this->_index = 0;
	else
		this->_index = (this->_index + 1) % 8;;
	this->_contact[this->_index].setIndex(this->_index);
	std::cout << "Please enter the first name: ";
	std::cin >> firstName;
	this->_contact[this->_index].setFirstName(firstName);
	std::cout << "Please enter the last name: ";
	std::cin >> lastName;
	this->_contact[this->_index].setLastName(lastName);
	std::cout << "Please enter the nick name: ";
	std::cin >> nickName;
	this->_contact[this->_index].setNickName(nickName);
	std::cout << "Please enter the phone number: ";
	std::cin >> phoneNumber;
	this->_contact[this->_index].setPhoneNumber(phoneNumber);
	std::cout << "Please enter the darkest secret: ";
	std::cin >> darkestSecret;
	this->_contact[this->_index].setDarkestSecret(darkestSecret);
	std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::searchContact(void)
{
	int 		i = 0;
	std::string	tmp;
	
	if (_contact[0].getFirstName().empty())
	{
		this->_index = 0;
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << "|" << std::endl;
	while (i < 8)
	{
		if (!this->_contact[i].getFirstName().empty())
		{
			std::cout << std::setw(10) << this->_contact[i].getIndex() << "|";
			std::cout << std::setw(10) << this->_contact[i].getFirstName() << "|";
			std::cout << std::setw(10) << this->_contact[i].getLastName() << "|";
			std::cout << std::setw(10) << this->_contact[i].getNickName() << "|" << std::endl;
		}
		i++;
	}
	std::cout << "Please enter the index of the contact you want to see: ";
	std::cin >> tmp;
	i = std::atoi(tmp.c_str());
	if (i < 0 || i > 8 || this->_contact[i].getFirstName().empty())
	{
		std::cout << "Invalid index, please try again." << std::endl;
		return ;
	}
	this->printContact(i);
}

void PhoneBook::printContact(int index)
{
	std::cout << "First Name: " << this->_contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contact[index].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->_contact[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->_contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contact[index].getDarkestSecret() << std::endl;
}
