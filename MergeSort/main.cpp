#include <iostream>
#include "MergeSort.h"

bool compare(const int & a, const int & b) {
    return a < b;
}
int main() {
    size_t size;
    std::cin >> size;
    auto * array = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    mergeSortIterative(array, 0, size - 1, compare);

    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}