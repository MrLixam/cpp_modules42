#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void search();
	private:
		Contact contacts[8];	
		void searchDisplay();
		int displayContact(int n);
		int _index;
		bool first;
};

#endif