/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:14:29 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/05 18:11:49 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) { }

Contact::~Contact(void) { }

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void	Contact::setIndex(int index)
{
	this->_index = index;
}

std::string	Contact::getFirstName(void) { return this->_firstName; }
std::string	Contact::getLastName(void) { return this->_lastName; }
std::string	Contact::getNickName(void) { return this->_nickName; }
std::string	Contact::getPhoneNumber(void) { return this->_phoneNumber; }
std::string	Contact::getDarkestSecret(void) { return this->_darkestSecret; }
int			Contact::getIndex(void) { return this->_index; }