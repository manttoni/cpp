#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}

	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
	{
		std::cerr << "Failed to open file 'data.csv'" << std::endl;
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
	dataFile.close();
	std::cout << "BitcoinExchange has succesfully loaded the database" << std::endl;

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open file '" << argv[1] << "'" << std::endl;
		return 4;
	}

	// start checking rates
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line == "date | value")
			continue;
		try
		{
			std::tuple<std::chrono::year_month_day, float> values = parseTuple(line, '|');
			float multiplier = std::get<1>(values);
			if (multiplier > 1000 || multiplier < 0)
				throw std::runtime_error("Too big a number");
			auto rate = be.getRate(std::get<0>(values));
			std::cout << rate->first << " => " << multiplier << " = " << multiplier * rate->second << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}
