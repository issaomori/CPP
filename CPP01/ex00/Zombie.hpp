#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
//classe Zombie que será responsável por armazenar as informações de cada zumbi.
{
    private:
    //variáveis de membro da classe Zombie que apenas podem ser acessadas por métodos da classe.
        std::string _name;
        //variável de membro que armazena o nome do zumbi.
    public:
    //métodos públicos da classe Zombie que podem ser acessados por qualquer classe.
        Zombie();
        //construtor da classe Zombie que serve para inicializar as variáveis de membro da classe.
        ~Zombie();
        //destrutor da classe Zombie que serve para destruir as variáveis de membro da classe.

        Zombie(std::string name);
        //construtor da classe Zombie que serve para inicializar as variáveis de membro da classe. Neste caso, o construtor recebe uma string que será o nome do zumbi.
        void announce();
        //método responsável por printar na tela o nome do zumbi.
        Zombie* newZombie( std::string name );
        //método responsável por criar um novo zumbi.
        void randomChump( std::string name );
        //método responsável por criar um novo zumbi e printar na tela o nome do zumbi.
};

// Por que estou criando métodos fora da classe?
// Porque estou criando métodos que não precisam acessar variáveis de membro da classe. Por exemplo, o método newZombie() não precisa acessar nenhuma variável de membro da classe Zombie. Por isso, não preciso criar o método dentro da classe Zombie. E como o método não precisa acessar nenhuma variável de membro da classe Zombie, ele pode ser criado fora da classe Zombie. Caso eu quisesse, eu poderia criar essas funções dentro da classe e utilizar o método estático.
Zombie* newZombie( std::string name );
//método responsável por criar um novo zumbi.
void randomChump( std::string name );
//método responsável por criar um novo zumbi e printar na tela o nome do zumbi.

#endif