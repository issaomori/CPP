#include "Contact.hpp"

Contact::Contact(){}

void Contact::defContactInfo(){
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);
}

void Contact::showContactInfo(){
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phone << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}
