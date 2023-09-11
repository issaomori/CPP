//Neste exercício aprenderemos a utilização da memória dinâmica em CPP.
#include "Zombie.hpp"

int main( void ){
    std::string zombie_name;
    //String que armazena o nome do zombie que será criado.
    
    std::cout << "Enter a name for your zombie(stack): ";
    //Printa na tela a mensagem para o usuário inserir o nome do zombie.
    std::cin >> zombie_name;
    //Pega a string inserida pelo usuário e armazena na variável zombie_name.
    Zombie zombie_stack(zombie_name);
    //Cria uma instância da classe Zombie chamada zombie_stack e passa o nome do zombie, que foi pego anteriormente, como argumento.

    std::cout << "Enter a name for your zombie(heap): ";
    //Printa na tela a mensagem para o usuário inserir o nome do zombie para termos um zombie na memória heap.
    //Qual a diferença entre a memória stack e heap?
    // A diferença entre memória stack e memória heap reside na alocação e gerenciamento de memória. A memória stack é usada para variáveis locais com gerenciamento automático, seguindo a ordem LIFO. A memória heap permite alocação dinâmica controlada manualmente pelo programador, frequentemente envolvendo ponteiros. Exemplo: Variáveis na memória stack são criadas automaticamente dentro de funções e liberadas quando a função retorna, enquanto na memória heap, a alocação e desalocação de memória requerem ação manual, como em alocação com new e liberação com delete em C++.
    //Resumindo a stack quem controla é a máquina e a heap quem controla é o programador.
    std::cin >> zombie_name;
    //Pega a string inserida pelo usuário e armazena na variável zombie_name.

    Zombie* zombie_heap = newZombie(zombie_name);
    //Cria uma instância da classe Zombie chamada zombie_heap e passa o nome do zombie, que foi pego anteriormente, como argumento.
    zombie_heap->announce();
    //Chama o método announce, que faz o barulho do zombie, da instância zombie_heap.
    delete zombie_heap;
    //Libera a memória heap que foi alocada para a instância zombie_heap.

    std::cout << "Create ramdom name of Zoombie(ramdom): ";
    //Printa na tela a mensagem para o usuário inserir o nome do zombie para termos um zombie na memória heap.
    randomChump("Ronaldo");
    //Cria uma instância da classe Zombie chamada zombie_heap e passa o nome do zombie, que foi pego anteriormente, como argumento.

    return 0;
}
