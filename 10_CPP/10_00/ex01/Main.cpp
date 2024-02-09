/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:22:15 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/07 15:55:46 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phone;

	std::cout << "Welcome " << std::getenv("USER") << "!\n" << std::endl;
	while (1)
	{
		std::string	command;
		std::cout << "Please enter a command: ";
		std::cout << "ADD, SEARCH, EXIT\n";
		std::cout << std::endl;
		std::cin >> command;
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phone.addContact();
		else if (command == "SEARCH")
			phone.searchContact();
		else
			std::cout << "Invalid command, please try again." << std::endl;
	}
	return (0);
}