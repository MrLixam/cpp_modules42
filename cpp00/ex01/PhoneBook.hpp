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
		void search_display();
		int display_contact(int n);
		int i;
		bool first;
};

#endif