#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <chrono>

class BitcoinExchange
{
	private:
		std::map<std::chrono::year_month_day, float> exrates;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other) = delete;
		BitcoinExchange& operator=(const BitcoinExchange &other);

		BitcoinExchange(std::ifstream &file);
		~BitcoinExchange();

		std::map<std::chrono::year_month_day, float>::const_iterator
		getRate(const std::chrono::year_month_day &ymd) const;
};

std::map<std::chrono::year_month_day, float> readCSV(std::ifstream &file);
std::tuple<std::chrono::year_month_day, float> parseTuple(const std::string &line, const char sep);
std::string trim(const std::string& str);
std::ostream& operator<<(std::ostream& os, const std::chrono::year_month_day& ymd);

#endif
