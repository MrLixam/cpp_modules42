#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;
		std::string _filename;

		int initData(void);
		void parseFile(void);
		double matchDate(std::string base_date);
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
};

#endif