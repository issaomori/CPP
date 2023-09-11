#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    //método construtor que inicializa as variáveis de membro da classe Zombie.
    this->_name = name;
    //inicializa a variável de membro _name com o nome passado como parâmetro.
    std::cout << "Zombie created" << std::endl;
    //printa na tela a mensagem de que o zumbi foi criado.
}

Zombie::~Zombie( void ){
    //método destrutor que destrói as variáveis de membro da classe Zombie.
    std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
    //printa na tela a mensagem de que o zumbi foi destruído.
}

void Zombie::announce( void ){
    //método responsável por printar na tela o barulho do zumbi.
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
    //printa na tela o nome e o barulho do zumbi.
}
