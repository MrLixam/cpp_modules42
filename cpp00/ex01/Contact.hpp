#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact{
	public:
		Contact();
		void updateInfo(std::string first_name, std::string last_name, std::string nickname, std::string phone_nbr, std::string secret);
		~Contact();
		void searchInfo();
		void displayInfo();
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_nbr;
		std::string secret;
};

#endif