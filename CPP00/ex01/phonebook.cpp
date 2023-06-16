#include "phonebook.hpp"

class Contact{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phone;
	std::string secret;

	public:
	Contact() {}
	void defContactInfo(){
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
	void showContactInfo(){
		std::cout << "First name: " << firstName << std::endl;
		std::cout << "Last name: " << lastName << std::endl;
		std::cout << "Nickname: " << nickName << std::endl;
		std::cout << "Phone number: " << phone << std::endl;
		std::cout << "Darkest secret: " << secret << std::endl;
	}
};

class PhoneBook{
	private:
	static const int maxContacts = 8;
	Contact contacts[maxContacts];
	int contactsCount;

	public:
	PhoneBook() : contactsCount(0) {}

	void addContacts(){
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
			contacts[contactsCount % maxContacts] = newContact;
			contactsCount++;
		}
	}
};

int	main(){

	std::string line_command;
	while (1){
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, line_command);
		if (line_command == "ADD")
			std::cout << "adcionar" << std::endl;
		else if (line_command == "SEARCH")
			std::cout << "procurar" << std::endl;
		else if (line_command == "EXIT"){

			std::cout << "sair" << std::endl;
			break ;
		}
		else
			std::cout << "Error. Command is invalid." << std::endl;
	}
	return 0;
}
