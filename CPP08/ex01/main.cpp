#include "Span.hpp"
#include <iostream>

int main() {
    try {
        // Create an instance of Span with capacity 5
        Span sp = Span(5);

        // Adding numbers
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // Display the vector contents
        const std::vector<int>& vect = sp.getVect();
        std::cout << "Vector contents: ";
        for (size_t i = 0; i < vect.size(); ++i) {
            std::cout << vect[i] << " ";
        }
        std::cout << std::endl;

        // Calculate and display shortest and longest spans
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Create another instance of Span
        Span sp2 = Span(3);

        // Adding a range of numbers
        int arr[] = { 1, 5, 2 };
        sp2.addRange(arr, arr + sizeof(arr) / sizeof(arr[0]));

        // Display the vector contents
        const std::vector<int>& vect2 = sp2.getVect();
        std::cout << "Vector contents: ";
        for (size_t i = 0; i < vect2.size(); ++i) {
            std::cout << vect2[i] << " ";
        }
        std::cout << std::endl;

        // Try to calculate shortest and longest spans (expect exceptions)
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
