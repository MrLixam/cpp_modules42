#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void search_display();
		int display_contact(int n);
	private:
		Contact contacts[8];	
		int i;
};

#endif