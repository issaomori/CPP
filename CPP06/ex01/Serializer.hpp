#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp" 
#include <iostream>
uintptr_t serializer(Data *ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserializer(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

#endif
