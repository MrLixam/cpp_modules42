#include "BitcoinExchange.hpp"

#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <algorithm>

static int parseDate(std::string date, bool mode)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
	{
		if (mode)
			std::cout << "Invalid date format => " << date << "\n";
		return (1);
	}
	for (long unsigned i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
		{
			if (mode)
				std::cout << "Date format invalid => " << date << "caca" << "\n";
			return (1);
		}
	}
	size_t a = date.find('-'), b = date.rfind('-');
	errno = 0;
	unsigned int year = strtol(date.c_str(),NULL, 10);
	unsigned int month = strtol(date.c_str() + a + 1, NULL, 10);
	unsigned int day = strtol(date.c_str() + b + 1, NULL, 10);

	if (errno == ERANGE)
	{
		if (mode)
			std::cout << "date string conversion overflowed => " << date << "\n";
	}
	if (month < 1 || month > 12)
	{
		if (mode)
			std::cout << "Invalid Month => " << date << "\n";
		return (1);
	}
	if (day < 1)
	{
		if (mode)
			std::cout << "Invalid day => " << date << "\n";
		return (1);
	}
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31)
			{
				if (mode)
					std::cout << "Invalid day => " << date << "\n";
				return (1);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
			{
				if (mode)
					std::cout << "Invalid day => " << date << "\n";
				return (1);
			}
			break;
		case 2:
			if (((year%400==0) || ((year%100!=0)&&(year%4==0))) && day > 29)
			{
				if (mode)
					std::cout << "Invalid day => " << date << "\n";
				return (1);
			}
			else if (day > 28)
			{
				if (mode)
					std::cout << "Invalid day => " << date << "\n";
				return (1);
			}
			break;
	}
	return (0);
}

int BitcoinExchange::initData(void)
{
	std::ifstream infile("data.csv", std::ios::in);
	std::string buffer;

	if (!infile.is_open())
	{
		std::cerr << "Could not open database, aborting" << std::endl;
		return (1);
	}
	if (!infile.good())
	{
		std::cerr << "there was an error while opening database, aborting" << std::endl;
		return (1);
	}
	getline(infile, buffer);
	if (buffer != "date,exchange_rate")
	{
		infile.clear();
		infile.seekg(0);
	}
	unsigned int i = 0;
	while (!infile.eof())
	{
		std::string date;
		std::string value;

		if (!infile.good())
		{
			std::cerr << "An operation caused an error on the database, aborting" << std::endl;
			return (1);
		}
		getline(infile, buffer);
		if (buffer.size() == 0)
			break;
		
		size_t comma = buffer.find(',');
		if (comma == std::string::npos)
		{
			std::cerr << "Missing comma at line: " << i << std::endl;
			return (1);
		}

		date = buffer.substr(0, comma);
		value = buffer.substr(comma + 1, buffer.size());

		if (!date.size())
			std::cerr << "Missing date at line: " << i << std::endl;
		if (!value.size())
			std::cerr << "Missing value at line: " << i << std::endl;
		if (!date.size() || !value.size())
		{
			std::cerr << "Database Corrupted, aborting" << std::endl;
			return (1);
		}

		if (parseDate(date, 0))
		{
			std::cerr << "Database Corrupted, aborting, with error line: " << i << std::endl;
			return (1);
		}

		char *test;
		errno = 0;
		long double llvalue = strtod(value.c_str(), &test);
		if (*test != 0)
		{
			std::cerr << "Value has invalid symbols, line: " << i << std::endl;
			std::cerr << "Database Corrupted, aborting" << std::endl;
			return (1);
		}
		if (errno == ERANGE)
		{
			std::cerr << "value not representable" << std::endl;
			std::cerr << "Database Corrupted, aborting" << std::endl;
			return (1);
		}

		_database[date] = llvalue;
		i++;
	}
	if (_database.size() == 0)
	{
		std::cerr << "Empty Database, aborting" << std::endl;
		return (1);
	}
	return (0);
}
double BitcoinExchange::matchDate(std::string base_date)
{
	std::map<std::string, double>::iterator it = _database.upper_bound(base_date);

	if (it == _database.begin())
	{
		std::cout << "given date older than all entries\n";
		return (-1);
	}
	it--;
	return (it->second);
}

void BitcoinExchange::parseFile(void)
{
	std::ifstream infile(_filename.c_str(), std::ios::in);
	std::string buffer;

	if (!infile.is_open())
	{
		std::cerr << "Could not open file, aborting" << std::endl;
		return ;
	}
	if (!infile.good())
	{
		std::cerr << "there was an error while opening file, aborting" << std::endl;
		return ;
	}
	getline(infile, buffer);
	if (buffer != "date | value")
		infile.seekg(0);
	while (!infile.eof())
	{
		std::string date;
		std::string value;

		if (!infile.good())
		{
			std::cout << "An operation caused an error on the file, aborting" << std::endl;
			return ;
		}

		getline(infile, buffer);
		if (buffer.size() == 0)
			break;
		
		size_t pipe = buffer.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Missing pipe => '" << buffer << "'\n";
			continue;
		}
		if (pipe == 0)
		{
			std::cout << "Missing date => '" << buffer << "'\n";
		}
		if (buffer[pipe + 1] == 0)
		{
			std::cout << "Missing value => '" << buffer << "'\n";
		}
		date = buffer.substr(0, pipe - 1);
		value = buffer.substr(pipe + 2, buffer.size());
		if (!date.size())
			std::cout << "Missing date => '" << buffer << "'\n";
		if (!value.size())
			std::cout << "Missing value => '" << buffer << "'\n";
		if (!date.size() || !value.size())
			continue ;
		if (parseDate(date, 1))
			continue;
		
		char * test;
		errno = 0;
		double dvalue = strtod(value.c_str(), &test);
		if (*test != 0)
		{
			std::cout << "Ivalid symbols in value => '" << buffer << "'\n";
			continue;
		}
		if (errno == ERANGE || dvalue > 1000 || dvalue < 0)
		{
			std::cout << "value must be a positive integer or float between 0  and 1000 => '" << buffer << "'\n";
			continue ; 
		}

		double db_result = matchDate(date);
		if (db_result == -1)
			continue ;
		
		long double result = dvalue * db_result;
		if (result == std::numeric_limits<long double>::infinity()) 
		{
			std::cout << date << " => " << "Could not represent value in a long double !\n";
			continue ;
		}

		std::cout << date << " => " << value << " = " <<  result << "\n";
	}
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	_filename = filename; 
	if (initData())
		return;
	parseFile();
}

BitcoinExchange::~BitcoinExchange(void) { }