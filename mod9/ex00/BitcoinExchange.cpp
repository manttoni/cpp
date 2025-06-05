#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <tuple>
#include <sstream>
#include <string>
#include <iomanip>

std::string trim(const std::string& str)
{
	auto begin = std::find_if_not(str.begin(), str.end(), ::isspace);
	auto end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();

	if (begin >= end)
		return "";
	return std::string(begin, end);
}

Date parseDate(const std::string& dateStr)
{
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        throw std::runtime_error("Failed to parse date string");
    }
    return std::chrono::year_month_day{
        std::chrono::year{tm.tm_year + 1900},
        std::chrono::month{static_cast<unsigned int>(tm.tm_mon + 1)},
        std::chrono::day{static_cast<unsigned int>(tm.tm_mday)}
    };
}

std::tuple<Date, float> parseTuple(const std::string &line, const char sep)
{
	std::istringstream ss(line);

	// parse comma separated line
	std::string left;
	std::string right;
	getline(ss, left, sep);
	ss >> right;
	left = trim(left);
	right = trim(right);
	if (left.empty() || right.empty())
		throw std::runtime_error("Can't have empty values");

	// get date
	Date ymd = parseDate(left);

	// get rate
	float rate;
	try
	{
		rate = stof(right);
	}
	catch (std::exception &e)
	{
		throw std::runtime_error("Invalid rate");
	}
	if (rate < 0)
		throw std::runtime_error("Rate can't be negative");

	return std::make_tuple(ymd, rate);
}

std::map<Date, float> readCSV(std::ifstream &file)
{
	std::map<Date, float> csvMap;
	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		std::tuple<Date, float> values = parseTuple(line, ',');
		Date ymd = std::get<0>(values);
		float rate = std::get<1>(values);
		csvMap[ymd] = rate;
	}
	return csvMap;
}

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	exrates = readCSV(file);
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : exrates(other.exrates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		exrates = other.exrates;
	return *this;
}

float BitcoinExchange::getRate(const std::chrono::year_month_day &ymd) const
{
	auto it = exrates.lower_bound(ymd);
	if (it != exrates.end() && it->first == ymd)
		// exact date found
		return it->second;
	else if (it == exrates.begin())
		throw std::runtime_error("No rate exists for this or earlier date");
	else
	{
		// exact date not found, but there is a previous one
		it--; // iterator is pointing at the previous element of exrates
		return it->second;
	}
}

std::ostream& operator<<(std::ostream& os, const Date &ymd)
{
	int y = int(ymd.year());
	unsigned m = unsigned(ymd.month());
	unsigned d = unsigned(ymd.day());
	os << y << "-" << m << "-" << d;
	return os;
}
