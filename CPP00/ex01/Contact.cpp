#include "Contact.hpp"

Contact::Contact(){}
//construtor da classe Contact que serve para inicializar as variáveis de membro da classe.

void Contact::defContactInfo(Contact &buffer){
//método responsável por preencher as variáveis de membro da classe Contact com as informações do contato.

	Contact aux;
	//variável auxiliar para armazenar as informações do contato e no futuro passar para o buffer. Ela é importante para que no meu buffer não vá informações erradas, como letras no lugar dos números do telefone, ou salve o contato vazio.
	std::cout << "Enter first name: ";
	//printa na tela a mensagem para o usuário inserir o primeiro nome do contato.
	std::getline(std::cin, aux.firstName);
	//pega a string inserida pelo usuário e armazena na variável auxiliar.
	if (aux.firstName.empty()){
		//verifica se a string está vazia.
		std::cout << "Empty first name." << std::endl;
		//printa na tela a mensagem de erro. caso esteja vazia
		return ;
		//retorna para a função main.
	}

	std::cout << "Enter last name: ";
	//printa na tela a mensagem para o usuário inserir o último nome do contato.
	std::getline(std::cin, aux.lastName);
	//pega a string inserida pelo usuário e armazena na variável auxiliar.
	if (aux.lastName.empty()){
		//verifica se a string está vazia.
		std::cout << "Empty last name." << std::endl;
		//printa na tela a mensagem de erro. caso esteja vazia
		return ;
		//retorna para a função main.
	}

	std::cout << "Enter nickname: ";
	//printa na tela a mensagem para o usuário inserir o apelido do contato.
	std::getline(std::cin, aux.nickName);
	//pega a string inserida pelo usuário e armazena na variável auxiliar.
	if (aux.nickName.empty()){
		//verifica se a string está vazia.
		std::cout << "Empty nickname." << std::endl;
		//printa na tela a mensagem de erro. caso esteja vazia
		return ;
		//retorna para a função main.
	}
	std::cout << "Enter phone number: ";
	//printa na tela a mensagem para o usuário inserir o número do telefone do contato.
	std::getline(std::cin, aux.phone);
	//pega a string inserida pelo usuário e armazena na variável auxiliar.
	if (!isNumeric(aux.phone)){
		//verifica se a string é numérica.

		std::cout << "Invalid number phone." << std::endl;
		//printa na tela a mensagem de erro. caso não seja numérica.
		return ;
		//retorna para a função main.
	}
	else if (aux.phone == ""){
		//verifica se a string está vazia.
		std::cout << "Empty number phone." << std::endl;
		//printa na tela a mensagem de erro. caso esteja vazia
		return ;
		//retorna para a função main.
	}

	std::cout << "Enter darkest secret: ";
	//printa na tela a mensagem para o usuário inserir o segredo mais sombrio do contato.
	std::getline(std::cin, aux.secret);
	//pega a string inserida pelo usuário e armazena na variável auxiliar.
	if (aux.secret == ""){
		//verifica se a string está vazia.
		std::cout << "Empty darkest secret." << std::endl;
		//printa na tela a mensagem de erro. caso esteja vazia
		return ;
		//retorna para a função main.
	}
	buffer = aux;
	//passa as informações do contato da variável auxiliar para o buffer. Deste modo, o buffer não vai ter informações erradas. Anteriormente estava com erro que quando o usuário inseria uma letra no lugar do número do telefone, o buffer armazenava a letra e não o número e salvava o contato vazio.
}


void Contact::showContactInfo(){
//método responsável por printar na tela as informações do contato.
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phone << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

std::string Contact::getFirstName(){
	//método responsável por retornar o primeiro nome do contato.
	return this->firstName;
	//retorna o primeiro nome do contato.
	//O this serve para o compilador saber que estou me referindo a variável de membro dessa classe(Contacat) e não a variável herdada. Neste caso não há heranças e eu poderia utilizar apenas "return firstName". 
}
std::string Contact::getlastName(){
	//método responsável por retornar o último nome do contato.
	return this->lastName;
	//retorna o último nome do contato.
}
std::string Contact::getnickName(){
	//método responsável por retornar o apelido do contato.
	return this->nickName;
	//retorna o apelido do contato.
}

bool Contact::isNumeric(const std::string &str){
	//método responsável por verificar se uma string é numérica e será importante para pegar apenas inteiros sem caracteres.
	for (std::string::size_type i = 0; i < str.length(); i++){
		//Enquanto não chegar no fim da string, vai andando.
		if (!isdigit(str[i]))
			//verifica se o caractere não é um número.
			return false;
			//retorna falso, ou seja, não é numérico.
	}
	return true;
	//retorna verdadeiro, ou seja, é numérico.
}

bool Contact::isEmpty() const {
	//método responsável por verificar se o contato está vazio.
    return firstName.empty() && lastName.empty() && nickName.empty() && phone.empty() && secret.empty();
	//retorna verdadeiro se todas as variáveis de membro da classe Contact estiverem vazias. Ela é importante para não salvar contatos vazios.
}
