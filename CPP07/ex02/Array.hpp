#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    unsigned int _size;
    T *ptr;

public:
    class InvalidIndex : public std::exception {
    public:
        const char* what() const throw() {
            return "Index is out of range";
        }
    };

    Array() : _size(0), ptr(NULL) {}

    Array(unsigned int size) : _size(size), ptr(new T[size]) {}

    Array(const Array &src) : _size(src._size), ptr(new T[src._size]) {
        for (unsigned int i = 0; i < _size; i++) {
            ptr[i] = src[i];
        }
    }

    ~Array() {
        delete[] ptr;
    }

    Array &operator=(const Array &src) {
        if (this != &src) {
            delete[] ptr;
            _size = src._size;
            ptr = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                ptr[i] = src[i];
            }
        }
        return *this;
    }

    T &operator[](unsigned int i) {
        if (i >= _size) {
            throw InvalidIndex();
        }
        return ptr[i];
    }

    const T &operator[](unsigned int i) const {
        if (i >= _size) {
            throw InvalidIndex();
        }
        return ptr[i];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif
