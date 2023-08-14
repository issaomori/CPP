#include "Serializer.hpp"

int main() {
    Data *initial_pointer = new Data("Test if pointer is the same after deserialization");

    uintptr_t pointer_after_serialize = serializer(initial_pointer);

    Data *end_pointer = deserializer(pointer_after_serialize);

    bool same_memory_address = (initial_pointer == end_pointer);

    std::cout << "Pointer addresses comparison: " << (same_memory_address ? "Same" : "Different") << std::endl;

    std::cout << "Initial pointer address: " << initial_pointer << std::endl;
    std::cout << "End pointer address: " << end_pointer << std::endl;

    delete initial_pointer;
    return 0;
}
