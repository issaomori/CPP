class Contact{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phone;
	std::string secret;

	// public:
	// Contact() {}
}

int	main(){

	std::string line_command;
	while (1){
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD"){
			std::cout << "adcionar" << std::endl;
		else if (command == "SEARCH")
			std::cout << "procurar" << std::endl;
		else if (command == "EXIT")
			std::cout << "sair" << std::endl;
			break ;
		else
			std::cout << "Error. Command is invalid." << std::endl;
		}
	}
	return 0;
}