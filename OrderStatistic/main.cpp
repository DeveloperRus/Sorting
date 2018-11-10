#include<vector>
#include <iostream>
#include "fstream"
#include "OrderStatistic.h"

/**
 * Функция для сравнения элементов
 * @param a первый элемент
 * @param b второй элемент
 * @return результат сравнения
 */
bool greater(const int &a, const int &b) {
    return a < b;
}

int main() {
    int n, k, A, B, C;

    std::ifstream input ("kth.in");
    input >> n >> k;

    std::vector<int> array(n);
    input >> A >> B >> C >> array[0] >> array[1];
    input.close();

    for (int i = 2; i < n; i++)// запись в массив
        array[i]= A * array[i-2] + B * array[i-1] + C;

    std::ofstream output("kth.out");
    output << orderStatistic(array, k, 0, n - 1, greater);
    output.close();

    return 0;
}
