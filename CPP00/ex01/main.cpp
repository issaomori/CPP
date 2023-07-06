# include "Phonebook.hpp"

int	main(){
    
    PhoneBook phone;
	std::string line_command;
	while (1){
		std::cin.clear();
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin >> std::ws, line_command);
		if (std::cin.eof()){
			std::cout << "Program finished with ctrl+D" << std::endl;
			return 1;
		}
		if (line_command == "ADD")
        {
            phone.addContacts();
        }
		else if (line_command == "SEARCH")
			phone.searchContacts();
			// std::cout << "procurar" << std::endl;
		else if (line_command == "EXIT")
			break ;
		else
		{
			std::cout << "Error. Command is invalid." << std::endl;
			std::cout << "|" << line_command << "|" << std::endl;
		}
	}
	return 0;
}
