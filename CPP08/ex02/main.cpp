#include "MutantStack.hpp"
#include <iostream>

int main() {
    try {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top element: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Stack size after pop: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Stack contents using iterator:" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << std::endl;
        }

        std::cout << "Copying the stack:" << std::endl;
        MutantStack<int> mstackCopy = mstack;
        while (!mstackCopy.empty()) {
            std::cout << "Copied element: " << mstackCopy.top() << std::endl;
            mstackCopy.pop();
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
