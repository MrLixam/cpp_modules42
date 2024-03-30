#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>


class Date
{
	private:
		unsigned int _year;
		unsigned int _month;
		unsigned int _day;
	public:
		Date(void);
		Date(unsigned int year, unsigned int month, unsigned int day);
		~Date();
		unsigned int getYear(void) const;
		unsigned int getMonth(void) const;
		unsigned int getDay(void) const;
		Date(const Date& copy);
		Date& operator=(const Date& copy);
		bool operator<(const Date& compare) const;
		bool operator>(const Date& compare) const;
		bool operator<=(const Date& compare) const;
		bool operator>=(const Date& compare) const;
		bool operator==(const Date& compare) const;
		bool operator!=(const Date& compare) const;
};

class BitcoinExchange
{
	private:
		std::map<Date, double> _database;
		std::string _filename;

		int initData(void);
		void parseFile(void);
		double matchDate(std::string base_date);
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& copy);
	public:
		~BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
};

#endif