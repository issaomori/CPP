# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook{
	private:
	static const int maxContacts = 8;

	Contact contacts[maxContacts];
	int contactsCount;

	public:
	PhoneBook() : contactsCount(0) {}

	void addContacts();
	void searchContacts();
};

#endif