#include <iostream>
#include <fstream>

int main() {
    int size; // Размер массива
    std::ifstream input("antiqs.in");

    input >> size;
    input.close();

    auto * array = new int [size];

    // Запись элементов в массив
    for (int i = 0; i < size; i++)
        array[i] = i + 1;

    // Переупорядочивание элементов, для плохой работы быстрой сортировки
    for (int i = 0; i < size; i++)
        std::swap(array[i], array[i / 2]);

    std::ofstream output("antiqs.out");

    // Запись результата в поток вывода
    for (int i = 0; i < size; i++)
        output << array[i] << " ";

    output.close();
    delete [] array;

    return 0;
}