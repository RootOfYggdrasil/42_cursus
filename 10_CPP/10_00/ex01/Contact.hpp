/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:14:27 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/05 18:11:33 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
# include <iostream> //std:cout, std::cin, std::endl, std::string
# include <iomanip>  // std::setw
# include <string>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	int			_index;

public:
	Contact(void);
	~Contact(void);
	void		setFirstName(std::string firstName);
	void		setLastName(std::string lastName);
	void		setNickName(std::string nickName);
	void		setPhoneNumber(std::string phoneNumber);
	void		setDarkestSecret(std::string darkestSecret);
	void		setIndex(int index);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
	int			getIndex(void);
};



#endif