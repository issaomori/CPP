# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
//biblioteca para usar o std::string, std::getline e std::cout
# include <iomanip>
//biblioteca para usar o std::setw

class Contact{
//classe Contact que será responsável por armazenar as informações de cada contato.	
	private:
	//variáveis de membro da classe Contact que apenas podem ser acessadas por métodos da classe.
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phone;
	std::string secret;

	public:
	//métodos públicos da classe Contact que podem ser acessados por qualquer classe.

    Contact();
	//construtor da classe Contact que serve para inicializar as variáveis de membro da classe.
	void defContactInfo(Contact &buffer);
	//método responsável por preencher as variáveis de membro da classe Contact com as informações do contato.
	void showContactInfo();
	//método responsável por printar na tela as informações do contato.
	std::string getFirstName();
	//método responsável por retornar o primeiro nome do contato.
	std::string getlastName();
	//método responsável por retornar o último nome do contato.
	std::string getnickName();
	//método responsável por retornar o apelido do contato.
	bool isNumeric(const std::string &str);
	//método responsável por verificar se uma string é numérica e será importante para pegar apenas inteiros sem caracteres.
	bool isEmpty() const ;
	//método responsável por verificar se o contato está vazio.
};

#endif
