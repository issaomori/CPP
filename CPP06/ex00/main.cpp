#include "Converter.hpp"

int main() {
    try {
        std::string input;

        std::cout << "Enter an input: ";
        std::cin >> input;

        Converter converter(input);

        converter.convertPrint();
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

