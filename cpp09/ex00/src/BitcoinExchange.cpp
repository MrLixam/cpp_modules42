#include "BitcoinExchange.hpp"

#include <string>
#include <fstream>
#include <iostream>

void BitcoinExchange::initData(void)
{
	std::ifstream infile("data.csv", std::ios::in);
	std::string buffer;

	if (!infile.is_open())
	{
		std::cerr << "Could not open database" << std::endl;
	}
	getline(infile, buffer);
	while (!infile.eof())
	{
		std::string date;
		std::string value;
		getline(infile, buffer);

		size_t comma = buffer.find(',');
		date = buffer.substr(0, comma);
		value = buffer.substr(comma, buffer.size());
		std::cout << "date: " << date << "\n";
		std::cout << "value: " << value  << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	_filename = filename; 
	initData();
}

BitcoinExchange::~BitcoinExchange(void) { }