#include "Form.hpp"

int main() {
    try {
        // Criando burocratas
        Bureaucrat bureaucrat1("Alice", 100);
        Bureaucrat bureaucrat2("Bob", 50);

        // Criando formas
        Form form1("Tax Form", 75, 100);
        Form form2("Approval Form", 40, 60);

        // Imprimindo informações iniciais das formas e dos burocratas
        std::cout << "Initial state of forms and bureaucrats:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << std::endl;

        // Tentando assinar as formas pelos burocratas
        std::cout << "Trying to sign the forms:" << std::endl;
        bureaucrat1.signForm(form1);
        bureaucrat2.signForm(form2);

        // Imprimindo o estado das formas após a tentativa de assinatura
        std::cout << "State of forms after signing attempt:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
