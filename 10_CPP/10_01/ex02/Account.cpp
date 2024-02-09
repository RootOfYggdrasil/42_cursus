/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:58:07 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/09 12:26:50 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void ) {return _nbAccounts;}
int		Account::getTotalAmount( void ) {return _totalAmount;}
int		Account::getNbDeposits( void ) {return _totalNbDeposits;}
int		Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}

Account::Account( int initial_deposit ) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	this->_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

Account::~Account( void ) {
	this->_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t		now = time(0);
	tm			*ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year;
	if (1 + ltm->tm_mon < 10)
		std::cout << "0";
	std::cout	 << 1 + ltm->tm_mon;
	if (ltm->tm_mday < 10)
		std::cout << "0";
	std::cout	 << ltm->tm_mday << "_";
	if (ltm->tm_hour < 10)
		std::cout << "0";
	std::cout	 << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << "0";
	std::cout	 << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0";
	std::cout	 << ltm->tm_sec << "] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount + deposit
				<< ";nb_deposits:" << ++this->_nbDeposits
				<< std::endl;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:" ;
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	else
		std::cout << withdrawal ;
	std::cout	<< ";amount:" << this->_amount - withdrawal
				<< ";nb_withdrawals:" << ++this->_nbWithdrawals
				<< std::endl;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	return true;
}

int	Account::checkAmount( void ) const {
	return (this->_amount);	
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

