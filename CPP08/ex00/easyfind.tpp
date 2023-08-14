#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int i) {
    typename T::iterator iter = std::find(container.begin(), container.end(), i);

    if (iter == container.end()) {
        throw NotFound();
    }
    return iter;
}

#endif
