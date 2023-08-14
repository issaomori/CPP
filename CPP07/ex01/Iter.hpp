#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* array, size_t len, void (*fptr)(T& elem)) {
    if (!array || len <= 0)
        return;
    for (size_t i = 0; i < len; i++)
        fptr(array[i]);
}

template<typename T>
void iter(T const* array, size_t len, void (*fptr)(T const& elem)) {
    if (!array || len <= 0)
        return;
    for (size_t i = 0; i < len; i++)
        fptr(array[i]);
}

template<typename T>
void printElem(T& elem) {
    std::cout << elem << " ";
}

template<typename T>
void printElem(T const& elem) {
    std::cout << elem << " ";
}

template<typename T>
void printElemLn(T& elem) {
    std::cout << elem << std::endl;
}

template<typename T>
void printElemLn(T const& elem) {
    std::cout << elem << std::endl;
}

template<typename T>
void addOne(T& elem) {
    elem++;
}

template<typename T>
void reduceOne(T& elem) {
    elem--;
}

#endif
