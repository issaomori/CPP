#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    //método responsável por criar um zombie.
    Zombie* zombie = new Zombie(name);
    //cria uma instância da classe Zombie chamada zombie e passa o nome do zombie, que foi pego anteriormente, como argumento.
    //Para que serve o new?
    //O new serve para alocar memória heap para a instância zombie. Portanto a classe Zombie instancia um objeto com ponteiro para poder receber a memória heap.
    return zombie;
    //retorna o zombie criado.
}
