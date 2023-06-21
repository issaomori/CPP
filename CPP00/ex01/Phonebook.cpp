#include "Phonebook.hpp"

void PhoneBook::addContacts(){
	if(contactsCount < maxContacts){
		Contact newContact;
		newContact.defContactInfo();
		contacts[contactsCount] = newContact;
		contactsCount++;
	}
	else{
		std::cout << "Phonebook is full." << std::endl;
		Contact newContact;
		newContact.defContactInfo();
		contactsCount = 0;
		contacts[contactsCount] = newContact;
		contactsCount++;
	}
}

void PhoneBook::searchContacts (){
	
}