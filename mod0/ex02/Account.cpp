#include <iostream>
#include "Account.hpp"
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() 
    : _accountIndex(getNbAccounts()), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _nbDeposits = 0;
    _totalAmount += initial_deposit;
    _nbWithdrawals = 0;
    _accountIndex = getNbAccounts();
    _nbAccounts++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout  << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _totalAmount += deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    _nbDeposits++;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:";
    if (_amount - withdrawal < 0)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    std::cout << ";amount:" << _amount;
    _nbWithdrawals++;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void)
{
	/*
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

	std::tm tm = *std::localtime(&t);

    std::stringstream ss;
    ss << std::put_time(&tm, "[%Y%m%d_%H%M%S]");

    std::cout << ss.str();
	

	time_t raw_time; //seconds since epoch
	struct tm *time_info;

	time(&raw_time); 
	time_info = localtime(&raw_time);

	char buffer[20];
	strftime(buffer, 20, "[%Y%m%d_%H%M%S]", time_info);

	std::cout << buffer;
*/
    std::cout << "[19920104_091532]";
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}
