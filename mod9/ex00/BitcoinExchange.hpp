#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <chrono>

typedef std::chrono::year_month_day Date;

class BitcoinExchange
{
	private:
		std::map<std::chrono::year_month_day, float> exrates;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		BitcoinExchange(std::ifstream &file);
		~BitcoinExchange();

		float getRate(const Date &ymd) const;
};

std::map<Date, float> readCSV(std::ifstream &file);
std::tuple<Date, float> parseTuple(const std::string &line, const char sep);
std::string trim(const std::string& str);
std::ostream& operator<<(std::ostream& os, const Date &ymd);

#endif
