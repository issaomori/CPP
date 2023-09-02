#include "Contact.hpp"

Contact::Contact(){}

void Contact::defContactInfo(Contact &buffer){

	Contact aux;
	std::cout << "Enter first name: ";
	std::getline(std::cin, aux.firstName);
	if (aux.firstName.empty()){
		std::cout << "Empty first name." << std::endl;
		return ;
	}

	std::cout << "Enter last name: ";
	std::getline(std::cin, aux.lastName);
	if (aux.lastName.empty()){
		std::cout << "Empty last name." << std::endl;
		return ;
	}

	std::cout << "Enter nickname: ";
	std::getline(std::cin, aux.nickName);
	if (aux.nickName.empty()){
		std::cout << "Empty nickname." << std::endl;
		return ;
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, aux.phone);
	if (!isNumeric(aux.phone)){

		std::cout << "Invalid number phone." << std::endl;
		return ;
	}
	else if (aux.phone == ""){
		std::cout << "Empty number phone." << std::endl;
		return ;
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, aux.secret);
	if (aux.secret == ""){
		std::cout << "Empty darkest secret." << std::endl;
		return ;
	}
	buffer = aux;

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

bool Contact::isNumeric(const std::string &str){
	for (std::string::size_type i = 0; i < str.length(); i++){
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool Contact::isEmpty() const {
    return firstName.empty() && lastName.empty() && nickName.empty() && phone.empty() && secret.empty();
}