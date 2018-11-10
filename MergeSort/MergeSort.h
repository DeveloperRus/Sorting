#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include <cstddef>

/**
 * Сливание подмассивов (Общая функция для всех реализаций)
 * @tparam Type тип хранимых элементов
 * @param array массив элементов
 * @param begin начало сортируемого отрезка
 * @param end конец сортируемого отрезка
 * @param compare функция для упорядочивания
 */
template <class Type>
void merge(Type *array, size_t begin, size_t end, bool (*compare) (const Type& a, const Type& b))
{
    size_t middle = (begin + end) / 2;
    size_t left = begin;
    size_t right = middle + 1;
    auto * result = new int[end - begin + 1];

    // Формировние результирующего массив
    for(size_t j = begin, i = 0; j <= end; ++j, ++i) {
        if ( (left <= middle) && (right > end || compare(array[left], array[right])) ) {
            result[i] = array[left];
            left++;
        } else {
            result[i] = array[right];
            right++;
        }
    }

    // Перезапись исходного массива данными результата слияния
    for (size_t j = begin, i = 0; j <= end; ++j, ++i) {
        array[j] = result[i];
    }

    delete [] result;
};

////////////////////////////////////// Рекурсивная реализация //////////////////////////////////////

/**
 * Рекурсивная реализация сортировки
 * @tparam Type тип хранимых элементов
 * @param array массив элементов
 * @param begin начало сортируемого отрезка
 * @param end конец сортируемого отрезка
 * @param compare функция для сливания
 */
template <class Type>
void mergeSort(Type * array, size_t begin, size_t end, bool (*compare) (const Type& a, const Type& b)) {
    if (begin < end) {
        mergeSort(array, begin, (begin + end) / 2, compare);
        mergeSort(array, (begin + end) / 2 + 1, end, compare);
        merge(array, begin, end, compare);
    }
};

////////////////////////////////////// Итеративная реализация //////////////////////////////////////

/**
 * Итеративная реализация сортировки
 * @tparam Type тип хранимых элементов
 * @param array массив элементов
 * @param begin начало сортируемого отрезка
 * @param end конец сортируемого отрезка
 * @param compare функция для сливания
 */
template <class Type>
void mergeSortIterative(Type * array, size_t begin, size_t end, bool (*compare) (const Type& a, const Type& b)) {
    for (size_t i = 1; i < end; i *= 2) {
        for (size_t j = 0; j < end - i; j += 2 * i) {
            mergeSort(array,j, ((j + 2 * i) < end ? (j + 2 * i) : end), compare);
        }
    }
};

#endif //MERGESORT_MERGESORT_H
