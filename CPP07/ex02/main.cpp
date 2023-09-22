#include <iostream>
#include <cstdlib>
#include "Array.hpp"

template <typename T>
void printArray(Array<T> const& arr) {
    //crio uma função que recebe um array como parâmetro e imprime o array
    for (size_t i = 0; i < arr.size(); i++) {
        //percorro o array
        std::cout << arr[i];
        //imprimo o array
    }
    std::cout << std::endl;
    //imprimo uma quebra de linha no final
}

int main() {
    std::cout << "Testing Array class:" << std::endl;

    // Test 1: Default constructor
    Array<int> intArrayVoid;
    //crio um array vazio
    std::cout << "Array size: " << intArrayVoid.size() << std::endl;
    //imprimo o tamanho do array

    // Teste2: Criando um array de inteiros e imprimindo
    Array<int> intArray(5);
    //crio um array de inteiros com tamanho 5
    intArray[0] = 0;
    intArray[1] = 1;
    intArray[2] = 2;
    intArray[3] = 3;
    intArray[4] = 4;
    //atribuo valores para o array
    std::cout << "Integer Array: ";
    printArray(intArray);
    //imprimo o array

    // Teste 3: Criando um array de caracteres e imprimindo
    Array<char> charArray(5);
    charArray[0] = 'M';
    charArray[1] = 'A';
    charArray[2] = 'S';
    charArray[3] = 'S';
    charArray[4] = 'A';
    std::cout << "Character Array: ";
    printArray(charArray);

    //Teste 4: Copiando o array de caracteres e modificando a cópia
    Array<char> copy(charArray);
    copy[0] = 'F';
    copy[1] = 'E';
    copy[2] = 'I';
    copy[3] = 'T';
    copy[4] = 'A';
    std::cout << "Copied Character Array: ";
    printArray(copy);

    // Test 5: Assignment operator and modifying original character array
    // Teste 5: Pego o Operador de atribuição e modifico do array de caracteres original
    Array<char> assign = charArray;
    //crio um array assign que recebe o array charArray
    assign[2] = 'N';
    //falo que quero trocar o valor da posição 2 do array assign por 'N'
    std::cout << "Modified Character Array: ";
    printArray(assign);

    //Teste 6: Tratamento de exceção para índice inválido (-1)
    try {
        charArray[-1] = 'x';
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Teste 7: Tratamento de exceção para índice inválido (além do tamanho do array)
    try {
        charArray[7] = 'x';
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}



#define MAX_VAL 750
//defino um valor maximo para o array

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    //crio um array de inteiros com o valor maximo definido
    int* mirror = new int[MAX_VAL];
    //crio um array de inteiros com o valor maximo definido que vai receber os mesmos valores do array numbers
    srand(time(NULL));
    //inicializo o random. Essa função gera um número aleatório baseado no tempo atual do sistema
    for (int i = 0; i < MAX_VAL; i++)
    //percorro o array numbers
    {
        const int value = rand();
        //crio uma constante que recebe um valor aleatório
        numbers[i] = value;
        //atribuo o valor aleatório para o array numbers
        mirror[i] = value;
        //atribuo o valor aleatório para o array mirror
    }
    {
        Array<int> tmp = numbers;
        //crio um array temporário que recebe os valores do array numbers
        Array<int> test(tmp);
        //crio um array temporário que recebe os valores do array tmp
    }

    for (int i = 0; i < MAX_VAL; i++)
    //percorro o array numbers
    {
        if (mirror[i] != numbers[i])
        //se os valores do array mirror forem diferentes dos valores do array numbers
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            //imprimo uma mensagem de erro
            return 1;
            //retorno 1
        }
    }
    try
    {
        numbers[-2] = 0;
        //tento atribuir o valor 0 para a posição -2 do array numbers
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        //imprimo uma mensagem de erro
    }
    try
    {
        numbers[MAX_VAL] = 0;
        //tento atribuir o valor 0 para a posição MAX_VAL do array numbers
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        //imprimo uma mensagem de erro
    }

    for (int i = 0; i < MAX_VAL; i++)
    //percorro o array numbers
    {
        numbers[i] = rand();
        //atribuo um valor aleatório para o array numbers
    }
    delete [] mirror;
    //deleto o array mirror
    return 0;
}

//Nessa main basicamente sairá nos dois catchs
//Quando você tenta acessar numbers[-2] e numbers[MAX_VAL], você está acessando índices fora dos limites válidos do array. O primeiro índice é negativo, e o segundo é maior ou igual a MAX_VAL, que é o tamanho do array. Isso resulta em comportamento indefinido no C++.
//No segundo caso o MAX_VAL vale 750, porém o array tem 750 posições, mas o índice da última posição é 749, pois o primeiro índice é 0. Então, o índice 750 está fora dos limites válidos do array.

