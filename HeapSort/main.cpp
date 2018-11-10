#include <iostream>
#include <fstream>
#include "BinaryHeap.h"

using namespace std;

int main() {
    size_t size;
    ifstream input("sort.in");
    input >> size;

    auto * array = new int[size];
    for (int i = 0; i < size; ++i) {
        input >> array[i];
    }
    input.close();

    BinaryHeap<int> heap(array, size);

    ofstream output("sort.out");
    heap.sort(output);

    output.close();
    return 0;
}