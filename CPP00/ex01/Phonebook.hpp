# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook{
	private:

	int i;
	Contact contacts[8];
	int contactsCount;

	public:
	PhoneBook();
	~PhoneBook();

	void addContacts();
	void searchContacts();
};

#endif