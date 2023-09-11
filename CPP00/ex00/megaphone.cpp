#include <iostream>

class	Megaphone{

public:

	Megaphone(void);
	~Megaphone(void);

	void shift_all(std::string argv);

	std::string error_msg;
};

Megaphone::Megaphone(void){
	Megaphone::error_msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	return ;
}

Megaphone::~Megaphone(void){
	return ;
}

void	Megaphone::shift_all(std::string argv){
	for (int i = 0; argv[i]; i++){
		if (argv[i] >= 97 && argv[i] <= 122)
			std::cout << (char)(argv[i] - 32);
		else
			std::cout << argv[i];
	}
}

int main(int argc, char **argv){
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
