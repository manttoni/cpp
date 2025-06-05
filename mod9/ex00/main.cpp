#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

std::ifstream openFile(const std::string &fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw std::runtime_error("Failed to open file: " + fileName);
	return file;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}

	std::ifstream dataFile, inputFile;
	try
	{
		dataFile = openFile("data.csv");
		inputFile = openFile(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}

	BitcoinExchange be;
	try
	{
		be = BitcoinExchange(dataFile);
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to instantiate BitcoinExchange: " << e.what() << std::endl;
		return 3;
	}

	// start checking rates
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line == "date | value")
			continue;
		try
		{
			std::tuple<Date, float> values = parseTuple(line, '|');
			float multiplier = std::get<1>(values);
			Date date = std::get<0>(values);
			float rate = be.getRate(date);
			if (multiplier > 1000 || multiplier < 0 || std::isinf(multiplier * rate))
				throw std::runtime_error("Too large a number");
			std::cout << date << " => " << multiplier << " = " << multiplier * rate << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}
