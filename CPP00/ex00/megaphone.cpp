#include <iostream>
//Esta linha inclui a biblioteca iostream, que é usada para entrada e saída padrão, como cin e cout.

class	Megaphone{
//Aqui é definida uma classe chamada Megaphone. Ela possui um construtor, um destrutor, um método chamado
//shift_all e uma variável de membro chamada error_msg. A variável de membro error_msg será usada para 
//armazenar uma mensagem de erro.
public:

	Megaphone(void);
	//construtor da classe
	~Megaphone(void);
	//destrutor da classe
	void shift_all(std::string argv);
	//método responsável por fazer os caracteres virarem maiúsculos.

	std::string error_msg;
	//string responsável por printar na tela a mensagem de erro.
};

Megaphone::Megaphone(void){
// Este é o construtor da classe Megaphone. Ele inicializa a variável de membro error_msg
// com a mensagem de erro "* LOUD AND UNBEARABLE FEEDBACK NOISE *".
	Megaphone::error_msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	return ;
}

Megaphone::~Megaphone(void){
// Este é o destrutor da classe Megaphone. Neste caso, ele não faz nada além de retornar.
	return ;
}

void	Megaphone::shift_all(std::string argv){
// Este é o método shift_all da classe Megaphone. Ele recebe uma string como argumento e
// itera por cada caractere da string. Se o caractere for uma letra minúscula (com base nos
// valores ASCII), ele o converte para maiúscula e o imprime. Caso contrário, ele imprime o
// caractere original.
	for (int i = 0; argv[i]; i++){
		if (argv[i] >= 97 && argv[i] <= 122)
			std::cout << (char)(argv[i] - 32);
		else
			std::cout << argv[i];
	}
}

int main(int argc, char **argv){
// A função main cria uma instância da classe Megaphone chamada m.
//Em seguida, verifica se há pelo menos um argumento de linha de comando. Se não houver argumentos,
//ele imprime a mensagem de erro da instância m. Se houver argumentos, ele chama o método shift_all da
//instância m para cada argumento e imprime uma nova linha após cada um.
	Megaphone m;
	if (argc == 1){

		std::cout << m.error_msg << std::endl;
		return 1;
	}
	for(int i = 1; argv[i]; i++){
		m.shift_all(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}

// Atributos: Os atributos são variáveis que representam as características ou propriedades dos objetos
// pertencentes a uma classe. Por exemplo, em uma classe "Carro", os atributos podem incluir "cor", 
// "marca", "modelo" e assim por diante. Os atributos definem o estado dos objetos.

// Métodos: Os métodos são funções que definem o comportamento dos objetos pertencentes a uma classe. Eles 
// representam as ações que um objeto pode realizar. Por exemplo, em uma classe "Carro", os métodos podem 
// incluir "ligar", "desligar", "acelerar" e "frear". Os métodos definem as operações que podem ser executadas 
// nos objetos.

// Construtores: Um construtor é um método especial que é chamado quando um novo objeto da classe é criado. 
// Ele é usado para inicializar os atributos do objeto. Em muitas linguagens de programação, o construtor tem o 
// mesmo nome que a classe e é chamado automaticamente quando um objeto é instanciado.

// Destrutores: Um destrutor é um método especial que é chamado quando um objeto é destruído ou liberado da 
// memória. Sua principal função é liberar recursos alocados pelo objeto, como memória ou conexões de arquivo.

// Visibilidade (ou modificadores de acesso): As classes geralmente definem a visibilidade de seus atributos e
// métodos, indicando quem pode acessá-los. Os três principais modificadores de acesso são:
// Public: Atributos e métodos públicos podem ser acessados de fora da classe.
// Private: Atributos e métodos privados só podem ser acessados dentro da própria classe.
// Protected: Atributos e métodos protegidos podem ser acessados dentro da própria classe e por subclasses
// (em herança).
// Membros estáticos: Além dos membros de instância (atributos e métodos que pertencem a objetos individuais), 
// as classes também podem ter membros estáticos, que pertencem à classe em si, em vez de instâncias específicas.
// Isso permite que você acesse esses membros sem criar um objeto da classe.