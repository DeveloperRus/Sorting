#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <functional>
#include <future>

/**
 * Стандартный алгоритм быстрой сортировки с рандомизированной выборкой опоры
 * @tparam Type тип хранимых элементов
 * @param array сортируемый массив
 * @param begin начальный элемент
 * @param end конечный элемент
 * @param compare функция для упорядочивания элементов
 */
template <class Type>
void quickSort(Type * array, long long int begin, long long int end, bool (*compare) (const Type& a, const Type& b)) {
    long long int i = begin;
    long long int j = end;
    Type pivot = array[begin + random() % (end - begin)]; // Опора сортировки

    // Разбиение массива
    while (i <= j) {
        while (compare(array[i], pivot)) i++;
        while (compare(pivot, array[j])) j--;
        if (i <= j)
            std::swap(array[i++], array[j--]);
    }

    // Рекурсивный вызов для подмассивов
    if (begin < j) quickSort(array, begin, j, compare);
    if (i < end) quickSort(array, i, end, compare);
};

#endif //QUICKSORT_QUICKSORT_H
