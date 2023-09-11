#include "Zombie.hpp"

void randomChump( std::string name ){
    //método responsável por criar um zombie aleatório. Ele já cria o zombie e printa na tela o barulho do zombie.
    Zombie zombie(name);
    //cria uma instância da classe Zombie chamada zombie e passa o nome do zombie, que foi pego anteriormente, como argumento.
    zombie.announce();
    //Chama o método announce, que faz o barulho do zombie, da instância zombie.
}
