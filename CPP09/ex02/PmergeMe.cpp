#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(PmergeMe const &copy){
	*this = copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs){
	(void)rhs;
	return (*this);
}

int compare(int x, int y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int PmergeMe::jacobsthal(int number) {
    return round((std::pow(2, number) + std::pow(-1, number - 1)) / 3);
}

std::vector<int> PmergeMe::pendingElementOrder(int number) {
    std::vector<int> response;
    for (int i = 0; jacobsthal(i) > number; ++i) {
        response.push_back(jacobsthal(i));
    }
    response.push_back(number);
    std::vector<int> order;
    for (size_t i = 1; i < response.size(); ++i) {
        int a = response[i - 1];
        int b = response[i];
        for (int j = b - 1; j >= a; --j) {
            order.push_back(j);
        }
    }
    return order;
}

std::deque<int> PmergeMe::pendingElementOrder_deque(int number) {
    std::deque<int> output_deque;

    // Inicialize o vetor response com os números de Jacobsthal até o primeiro número maior que number.
    std::vector<int> response;
    int i = 0;
    while (jacobsthal(i) > number) {
        response.push_back(jacobsthal(i));
        ++i;
    }

    // Adicione o número à resposta.
    response.push_back(number);

    // Construa a ordem diretamente no deque.
    for (size_t idx = 1; idx < response.size(); ++idx) {
        int start_range = response[idx - 1];
        int end_range = response[idx];
        for (int j = end_range - 1; j >= start_range; --j) {
            output_deque.push_back(j);
        }
    }

    return output_deque;
}

int PmergeMe::binarySearchInsertionPoint(Comparator comp, int n, const std::vector<int>& coll, int lowerBound, int upperBound) {
    if (lowerBound > upperBound) {
        return lowerBound;
    } else {
        int midIndex = (lowerBound + upperBound) / 2;
        int compResult = comp(n, coll[midIndex]);
        if (compResult == 1) {
            return binarySearchInsertionPoint(comp, n, coll, midIndex + 1, upperBound);
        } else if (compResult == 0) {
            return midIndex;
        } else {
            return binarySearchInsertionPoint(comp, n, coll, lowerBound, midIndex - 1);
        }
    }
}

// int PmergeMe::binarySearchInsertionPoint(Comparator comp, int value, const std::vector<int>& collection, int low, int high) {
//     // Ensure low is not greater than high, indicating the search is done.
//     if (low > high) {
//         return low;
//     } else {
//         // Calculate the middle index using integer division.
//         int midIndex = (low + high) / 2;
        
//         // Compare the value with the element at midIndex.
//         int compResult = comp(value, collection[midIndex]);
        
//         if (compResult == 1) {
//             // Value is greater, search the right half.
//             return binarySearchInsertionPoint(comp, value, collection, midIndex + 1, high);
//         } else if (compResult == 0) {
//             // Value is equal to the element at midIndex.
//             return midIndex;
//         } else {
//             // Value is smaller, search the left half.
//             return binarySearchInsertionPoint(comp, value, collection, low, midIndex - 1);
//         }
//     }
// }

std::vector<int> PmergeMe::mainChainUntil(int aIndex, const std::vector<int>& mainChain, const std::vector<int>& aPositions) {
    int end = aPositions[aIndex];
    return std::vector<int>(mainChain.begin(), mainChain.begin() + end);
}

void PmergeMe::binaryInsertLambda(int bIndex, Comparator comp, std::vector<int>& mainChain, std::vector<int>& aPositions, std::vector<int>& pendingElements) {
    int n = pendingElements[bIndex];
    int insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChainUntil(bIndex, mainChain, aPositions).size() - 1);
    for (size_t i = 0; i < aPositions.size(); ++i) {
        if (aPositions[i] >= insertIndex) {
            ++aPositions[i];
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
}

std::vector<int> PmergeMe::binaryInsert(Comparator comp, int n, const std::vector<int>& coll) {
    std::vector<int> newColl = coll;
    int insertIndex = binarySearchInsertionPoint(comp, n, coll, 0, coll.size() - 1);
    newColl.insert(newColl.begin() + insertIndex, n);
    return newColl;
}

std::deque<int> PmergeMe::binaryInsert(Comparator comp, int n, const std::deque<int>& coll) {
    std::deque<int> newColl = coll;
    int insertIndex = binarySearchInsertionPoint(comp, n, coll, 0, coll.size() - 1);
    newColl.insert(newColl.begin() + insertIndex, n);
    return newColl;
}

std::vector<int> PmergeMe::mergeInsertionSort(Comparator comp, const std::vector<int>& coll) {
    if (coll.size() < 2) {
        return coll;
    } else {
        std::vector<int> mainChain;
        std::vector<int> pendingElements;
        
        for (size_t i = 0; i < coll.size(); i++) {
            int n = coll[i];
            size_t insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChain.size() - 1);
            mainChain.insert(mainChain.begin() + insertIndex, n);
            pendingElements.push_back(n);
        }

        std::vector<int> aPositions(mainChain.size());
        for (size_t i = 0; i < mainChain.size(); ++i) {
            aPositions[i] = i;
        }

        std::vector<int> order = pendingElementOrder(pendingElements.size());
        for (size_t i = 0; i < order.size(); ++i) {
            binaryInsertLambda(order[i], comp, mainChain, aPositions, pendingElements);
        }

        return mainChain;
    }
}

std::deque<int> PmergeMe::mainChainUntilFunction(int aIndex, const std::deque<int>& mainChain, const std::deque<int>& aPositions) {
    int end = aPositions[aIndex];
    return std::deque<int>(mainChain.begin(), mainChain.begin() + end);
}

void PmergeMe::binaryInsertLambda(int bIndex, Comparator comp, std::deque<int>& mainChain, std::deque<int>& aPositions, std::deque<int>& pendingElements) {
    int n = pendingElements[bIndex];
    int insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChainUntilFunction(bIndex, mainChain, aPositions).size() - 1);
    for (size_t i = 0; i < aPositions.size(); ++i) {
        if (aPositions[i] >= insertIndex) {
            ++aPositions[i];
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
}

std::deque<int> PmergeMe::mergeInsertionSort_deque(Comparator comp, const std::deque<int>& coll) {
    if (coll.size() < 2) {
        return coll;
    } else {
        std::deque<int> mainChain;
        std::deque<int> pendingElements;

        for (size_t i = 0; i < coll.size(); i++) {
            int n = coll[i];
            size_t insertIndex = binarySearchInsertionPoint(comp, n, mainChain, 0, mainChain.size() - 1);
            mainChain.insert(mainChain.begin() + insertIndex, n);
            pendingElements.push_back(n);
        }

        std::deque<int> aPositions(mainChain.size());
        for (size_t i = 0; i < mainChain.size(); ++i) {
            aPositions[i] = i;
        }

        std::deque<int> order = pendingElementOrder_deque(pendingElements.size());
        for (size_t i = 0; i < order.size(); ++i) {
            binaryInsertLambda(order[i], comp, mainChain, aPositions, pendingElements);
        }

        return mainChain;
    }
}
