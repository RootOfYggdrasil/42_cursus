/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:26:52 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/30 18:30:32 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (size_t i = 1; i < argc; i++)
		for (size_t j = 0; j < strlen(argv[i]); j++)
			std::cout <<  (char)toupper(argv[i][j]);
	std::cout  << std::endl;
}
