#include "Contact.hpp"

Contact::Contact(){}

void Contact::defContactInfo(Contact &buffer){

	std::cout << "Enter first name: ";
	std::getline(std::cin, buffer.firstName);
	if (buffer.firstName == ""){
		std::cout << "Empty first name." << std::endl;
		return ;
	}

	std::cout << "Enter last name: ";
	std::getline(std::cin, buffer.lastName);
	if (buffer.lastName == ""){
		std::cout << "Empty last name." << std::endl;
		return ;
	}

	std::cout << "Enter nickname: ";
	std::getline(std::cin, buffer.nickName);
	if (buffer.nickName == ""){
		std::cout << "Empty nickname." << std::endl;
		return ;
	}

	std::cout << "Enter phone number: ";
	std::getline(std::cin, buffer.phone);
	if (!buffer.phone.find_first_not_of("0123456789")){

		std::cout << "Invalid number phone." << std::endl;
		return ;
	}
	else if (buffer.phone == ""){
		std::cout << "Empty number phone." << std::endl;
		return ;
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, buffer.secret);
	if (buffer.secret == ""){
		std::cout << "Empty darkest secret." << std::endl;
		return ;
	}
}


void Contact::showContactInfo(){
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phone << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

std::string Contact::getFirstName(){
	return this->firstName;
}
std::string Contact::getlastName(){
	return this->lastName;
}
std::string Contact::getnickName(){
	return this->nickName;
}
