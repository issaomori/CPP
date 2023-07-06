#include "Phonebook.hpp"

PhoneBook::PhoneBook(){
	this->i = 0;
	this->contactsCount = 0;
}
PhoneBook::~PhoneBook(){}

void PhoneBook::addContacts(){
	Contact buffer;

	this->contacts[this->i].defContactInfo(buffer);
	this->contacts[this->i] = buffer;
	std::cout << this->contacts[i].getFirstName() << std::endl;	
	std::cout << this->contacts[i].getlastName() << std::endl;	
	std::cout << this->contacts[i].getnickName() << std::endl;
	this->i++;
	if (this->contactsCount < 8)
		this->contactsCount++;
	if (this->i == 8)
		this->i = 0;
}

void PhoneBook::searchContacts(){
	if (this->contactsCount == 0){
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
			  << std::setw(10) << "Last Name" << " | "
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::setfill('-') << std::setw(46) << "-" << std::endl;
	std::cout << std::setfill(' ');

	int j = 0;
	while (j < this->contactsCount)
	{
		std::cout << std::setw(10) << j << " | "
			  	  << std::setw(10) << this->contacts[j].getFirstName() << " | "
			  	  << std::setw(10) << this->contacts[j].getlastName() << " | "
			  	  << std::setw(10) << this->contacts[j].getnickName() << std::endl;
		j++;
	}

	std::cout << "Insert the number of the contact you want to display: ";
	int number;
	std::cin >> number;

	if (number < 0 || number >= this->contactsCount){
		std::cout << "Invalid number" << std::endl;
	}
	else
		this->contacts[number].showContactInfo();
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
