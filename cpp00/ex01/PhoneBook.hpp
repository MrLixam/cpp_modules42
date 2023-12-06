#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact newContact);
		void search_display();
	private:
		Contact contacts[8];	
		int i;
};

#endif