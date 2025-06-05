#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <tuple>
#include <sstream>
#include <string>
#include <iomanip>
#include <regex>
#include <iostream>

std::string trim(const std::string& str)
{
	const std::string spaces = " \t\n\v\f\r";
	size_t begin = str.find_first_not_of(spaces);
	if (begin == std::string::npos)
		return "";

	size_t end = str.find_last_not_of(spaces);
	return str.substr(begin, end - begin + 1);
}

Date parseDate(const std::string& dateStr)
{
	std::tm tm = {};
	std::istringstream ss(dateStr);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		throw std::runtime_error("Failed to parse date string");
	return Date
	{
		std::chrono::year{tm.tm_year + 1900},
		std::chrono::month{static_cast<unsigned int>(tm.tm_mon + 1)},
		std::chrono::day{static_cast<unsigned int>(tm.tm_mday)}
	};
}

std::tuple<Date, float> parseTuple(const std::string &line, const char sep)
{
	std::istringstream ss(line);

	std::string left, right;
	getline(ss, left, sep);
	getline(ss, right);
	left = trim(left);
	right = trim(right);
	if (left.empty() || right.empty())
		throw std::runtime_error("Value can't be empty");

	std::regex datePattern(R"(^\d{4}-\d{1,2}-\d{1,2})");
	if (!std::regex_match(left, datePattern))
		throw std::runtime_error("Date doesn't match pattern");

	std::regex ratePattern(R"(^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$)");
	if (!std::regex_match(right, ratePattern))
		throw std::runtime_error("Value doesn't match pattern");

	Date ymd = parseDate(left);

	float rate;
	try
	{
		rate = stof(right);
	}
	catch (std::exception &e)
	{
		throw std::runtime_error("Value invalid");
	}
	if (rate < 0)
		throw std::runtime_error("Value can't be negative");

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

float BitcoinExchange::getRate(const Date &ymd) const
{
	auto it = exrates.lower_bound(ymd);
	if (it != exrates.end() && it->first == ymd)
		// exact date found
		return it->second;
	else if (it == exrates.begin())
		throw std::runtime_error("No rate exists for this or earlier date");
	else
		// exact date not found, but there is a previous one
		return (--it)->second;
}

std::ostream& operator<<(std::ostream& os, const Date &ymd)
{
	int y = int(ymd.year());
	unsigned m = unsigned(ymd.month());
	unsigned d = unsigned(ymd.day());
	os << y << "-" << m << "-" << d;
	return os;
}
