#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
		std::string _filename;

		void initData(void);
		void parseLine(std::string line);

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
};

#endif