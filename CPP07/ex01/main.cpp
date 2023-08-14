#include "Iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Original intArray: ";
    iter(intArray, 5, printElemLn);

    std::cout << "Original doubleArray: ";
    iter(doubleArray, 5, printElemLn);

    std::cout << "Original charArray: ";
    iter(charArray, 5, printElemLn);

    std::cout << "Incremented intArray: ";
    iter(intArray, 5, addOne);
    iter(intArray, 5, printElemLn);

    std::cout << "Decremented doubleArray: ";
    iter(doubleArray, 5, reduceOne);
    iter(doubleArray, 5, printElemLn);

    return 0;
}
