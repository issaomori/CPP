#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat best("Best", 0);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat worst("Worst", 200);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat high("High", 1);
    Bureaucrat low("Low", 150);
    Bureaucrat medium("Medium", 75);

    std::cout << std::endl;
    std::cout << "Bureaucrat grade:" << std::endl;
    std::cout << high;
    std::cout << medium;
    std::cout << low;
    std::cout << std::endl;

    std::cout << "Testing grade too high:" << std::endl;
    try {
        high.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "Testing grade too low:" << std::endl;
    try {
        low.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "Functional decrement:" << std::endl;
    try {
        medium.decrementGrade();
        std::cout << medium;
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "Functional increment:" << std::endl;
    try {
        medium.incrementGrade();
        std::cout << medium;
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
