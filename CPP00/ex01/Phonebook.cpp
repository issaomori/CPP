#include "Phonebook.hpp"

PhoneBook::PhoneBook(){
	//construtor da classe PhoneBook que serve para inicializar as variáveis de membro da classe. No CPP diferente do C, eu inicializo as variáveis de membro da classe no construtor, enquanto no C inicializava antes de começar a função.
	this->i = 0;
	//variável de membro que será usada para percorrer pelo array de contatos.
	this->contactsCount = 0;
	//variável de membro que será usada para contar quantos contatos foram adicionados.
}
PhoneBook::~PhoneBook(){}
//destrutor da classe PhoneBook que serve para destruir as variáveis de membro da classe. No CPP diferente do C, eu destruo as variáveis de membro da classe no destrutor, enquanto no C não precisava desse cuidado. é importante destruir as variáveis de membro da classe para não ter vazamento de memória, por isso apenas preenchemos o destrutor quando há alocação dinâmica de memória.

void PhoneBook::addContacts(){
	//método responsável por adicionar os contatos no array de contatos.
	Contact buffer;
	//variável auxiliar para armazenar as informações do contato e no futuro passar para o buffer. Ela é importante para que no meu buffer não vá informações erradas, como letras no lugar dos números do telefone, ou salve o contato vazio.

	 buffer.defContactInfo(buffer); // Preenche o buffer
    if (!buffer.isEmpty()) {
	//se o buffer não estiver vazio, ele adiciona o contato no array de contatos.
        this->contacts[this->i] = buffer;
		//adiciona o contato no array de contatos.
        std::cout << this->contacts[this->i].getFirstName() << std::endl;   
		//printa na tela o primeiro nome do contato. 
        std::cout << this->contacts[this->i].getlastName() << std::endl;
		//printa na tela o último nome do contato.    
        std::cout << this->contacts[this->i].getnickName() << std::endl;
		//printa na tela o apelido do contato.
        if (this->contactsCount < 8)
		//verifica se o número de contatos é menor que 8. E se for, posso salvar mais um contato.
            this->contactsCount++;
			//incrementa o número de contatos.
        this->i++;
		//incrementa o índice do array de contatos.
        if (this->i == 8){
		//verifica se o índice do array de contatos é igual a 8. E se for, ele volta para o índice 0. Porque caso chegue no valor de 8 contatos, preciso sobreescrever o primeiro contato salvo.
			std::cout << "Phonebook is full. The first contact is new." << std::endl;
            this->i = 0;
			//volta para o índice 0.

		}
	}
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

	std::cout << number << std::endl;
	if (number < 0 || number >= this->contactsCount){
		std::cout << "Invalid number" << std::endl;
	}
	else
		this->contacts[number].showContactInfo();
}
