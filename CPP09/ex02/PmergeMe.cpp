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

int PmergeMe::jacobsthal(int n) {
    return round((std::pow(2, n) + std::pow(-1, n - 1)) / 3);
}

std::vector<int> PmergeMe::pendingElementOrder(int number) {
    std::vector<int> response;
    for (int i = 0; jacobsthal(i) > number; ++i) {
        response.push_back(jacobsthal(i));
    }
    response.push_back(number);
    std::vector<int> output_vector;
    for (size_t i = 1; i < response.size(); ++i) {
        int start_range = response[i - 1];
        int end_range = response[i];
        for (int j = end_range - 1; j >= start_range; --j) {
            output_vector.push_back(j);
        }
    }
    return output_vector;
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

int PmergeMe::binarySearchInsertionPoint(Comparator comp, int value, const std::vector<int>& collection, int startIdx, int endIdx) {
    if (startIdx <= endIdx) {
        int midIdx = (startIdx + endIdx) / 2;
        int compResult = comp(value, collection[midIdx]);

        if (compResult == 0) {
            return midIdx;
        } else if (compResult == -1) {
            return binarySearchInsertionPoint(comp, value, collection, startIdx, midIdx - 1);
        } else {
            return binarySearchInsertionPoint(comp, value, collection, midIdx + 1, endIdx);
        }
    } else {
        return startIdx;
    }
}

int PmergeMe::binarySearchInsertionPoint(Comparator comp, int value, const std::deque<int>& collection, int startIdx, int endIdx) {
    if (startIdx <= endIdx) {
        int midIdx = (startIdx + endIdx) / 2;
        int compResult = comp(value, collection[midIdx]);

        if (compResult == 0) {
            return midIdx;
        } else if (compResult == -1) {
            return binarySearchInsertionPoint(comp, value, collection, startIdx, midIdx - 1);
        } else {
            return binarySearchInsertionPoint(comp, value, collection, midIdx + 1, endIdx);
        }
    } else {
        return startIdx;
    }
}

std::vector<int> PmergeMe::mainChainUntil(int p_index, const std::vector<int>& mainChain, const std::vector<int>& position_list) {
    int end = position_list[p_index];
    return std::vector<int>(mainChain.begin(), mainChain.begin() + end);
}

void PmergeMe::binaryInsertLambda(int element_index, Comparator compare, std::vector<int>& mainChain, std::vector<int>& position_list, std::vector<int>& elements_to_insert) {
    int n = elements_to_insert[element_index];
    int insertIndex = binarySearchInsertionPoint(compare, n, mainChain, 0, mainChainUntil(element_index, mainChain, position_list).size() - 1);
    for (size_t i = 0; i < position_list.size(); ++i) {
        if (position_list[i] >= insertIndex) {
            ++position_list[i];
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
}

std::vector<int> PmergeMe::binaryInsert(Comparator compare, int number, const std::vector<int>& coll) {
    std::vector<int> newColl = coll;
    int insertIndex = binarySearchInsertionPoint(compare, number, coll, 0, coll.size() - 1);
    newColl.insert(newColl.begin() + insertIndex, number);
    return newColl;
}

std::deque<int> PmergeMe::binaryInsert(Comparator compare, int number, const std::deque<int>& coll) {
    std::deque<int> newColl = coll;
    int insertIndex = binarySearchInsertionPoint(compare, number, coll, 0, coll.size() - 1);
    newColl.insert(newColl.begin() + insertIndex, number);
    return newColl;
}

std::vector<int> PmergeMe::mergeInsertionSort(Comparator compare, const std::vector<int>& collection) {
    if (collection.size() < 2) {
        return collection;
    } else {
        std::vector<int> sortedCollection;
        std::vector<int> elementsToInsert;

        for (size_t i = 0; i < collection.size(); i++) {
            int element = collection[i];
            size_t insertionPoint = binarySearchInsertionPoint(compare, element, sortedCollection, 0, sortedCollection.size() - 1);
            sortedCollection.insert(sortedCollection.begin() + insertionPoint, element);
            elementsToInsert.push_back(element);
        }

        std::vector<int> positions(sortedCollection.size());
        for (size_t i = 0; i < sortedCollection.size(); ++i) {
            positions[i] = i;
        }

        std::vector<int> order = pendingElementOrder(elementsToInsert.size());
        for (size_t i = 0; i < order.size(); ++i) {
            binaryInsertLambda(order[i], compare, sortedCollection, positions, elementsToInsert);
        }

        return sortedCollection;
    }
}

std::deque<int> PmergeMe::mainChainUntilFunction(int p_index, const std::deque<int>& mainChain, const std::deque<int>& positions_list) {
    int end = positions_list[p_index];
    return std::deque<int>(mainChain.begin(), mainChain.begin() + end);
}

void PmergeMe::binaryInsertLambda(int element_index, Comparator compare, std::deque<int>& mainChain, std::deque<int>& positions_list, std::deque<int>& pendingElements) {
    int n = pendingElements[element_index];
    int insertIndex = binarySearchInsertionPoint(compare, n, mainChain, 0, mainChainUntilFunction(element_index, mainChain, positions_list).size() - 1);
    for (size_t i = 0; i < positions_list.size(); ++i) {
        if (positions_list[i] >= insertIndex) {
            ++positions_list[i];
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
}

std::deque<int> PmergeMe::mergeInsertionSort_deque(Comparator compare, const std::deque<int>& coll) {
    if (coll.size() < 2) {
        return coll;
    } else {
        std::deque<int> mainChain;
        std::deque<int> pendingElements;

        for (size_t i = 0; i < coll.size(); i++) {
            int n = coll[i];
            size_t insertIndex = binarySearchInsertionPoint(compare, n, mainChain, 0, mainChain.size() - 1);
            mainChain.insert(mainChain.begin() + insertIndex, n);
            pendingElements.push_back(n);
        }

        std::deque<int> positions_list(mainChain.size());
        for (size_t i = 0; i < mainChain.size(); ++i) {
            positions_list[i] = i;
        }

        std::deque<int> order = pendingElementOrder_deque(pendingElements.size());
        for (size_t i = 0; i < order.size(); ++i) {
            binaryInsertLambda(order[i], compare, mainChain, positions_list, pendingElements);
        }
        return mainChain;
    }
}
