#ifndef ORDERSTATISTIC_ORDERSTATISTIC_H
#define ORDERSTATISTIC_ORDERSTATISTIC_H

#include<vector>
#include<functional>

/**
 * Сортировка вставкой (Вспомогательная функция)
 * @tparam Type тип сортируемых ключей
 * @param array вектор значений
 * @param begin индекс началаьного элемента сортировки
 * @param end индекс идущий последнего элемента сортировки
 * @param compare функция для задания порядка
 */
template <class Type>
void insertionSort(std::vector<Type> &array, size_t begin, size_t end, bool (*compare) (const Type& a, const Type& b)) {
    for (long long int i = begin; i <= end; ++i) {
        long long int j = i;
        while (j > 0 && compare(array[j - 1], array[j])) {
            std::swap(array[j - 1], array[j]);
            j--;
        }
    }
}

/**
 * Алгоритм порядковой статистики за линейное время в худшем случае
 * @tparam Type тип хранимых элементов
 * @param array вектор элементов
 * @param k позиция нужного элемента
 * @param begin начальный элемент рассматриваемого промежутка
 * @param end конечный элемент рассматриваемого промежутка
 * @param compare функция для задания порядка
 * @return элемент на заданной позиции
 */
template <class Type>
Type orderStatistic(std::vector<Type> &array, size_t k, size_t begin, size_t end,
                    bool (*compare) (const Type& a, const Type& b)) {
    std::vector<Type> medians; // Контейнер для хранения медиан групп
    long long int startGroup = begin; // Начало группы элементов
    long long int finishGroup = (begin + 4) < end ? (begin + 4) : end; // Конец группы элементов

    // Сортировка каждой группы с последующей выборкой медианы
    while (startGroup <= end) {
        insertionSort(array, startGroup, finishGroup, compare);
        // Выборка медианы с проверкой на границу массива
        size_t indexMedian = (startGroup + 2) < end ? (startGroup + 2) : end;
        medians.push_back(array[indexMedian]);
        // Сдвигание границ
        startGroup += 5;
        finishGroup += 5;
        // Проверка на границу массива
        finishGroup = finishGroup < end ? finishGroup : end;
    }

    size_t indexMedian = (medians.size() + 1) / 2; // Индекс медианы медиан
    Type mainMedian; // Медиана медиан

    // Если индекс больше 1, то мы не можем точно определить медиану медиан
    if (indexMedian > 1)
        mainMedian = orderStatistic(medians, indexMedian, 0, medians.size() - 1, compare);
    else
        mainMedian = medians[0];

    startGroup = begin;
    finishGroup = end;

    // Разбиение массива
    while (startGroup <= finishGroup) {
        while (compare(array[startGroup], mainMedian))
            startGroup++;
        while (compare(mainMedian, array[finishGroup]))
            finishGroup--;
        if (startGroup <= finishGroup)
            std::swap(array[startGroup++], array[finishGroup--]);
    }

    int less = 0, greater = 0, equally = 0;

    // Подсчет больших, меньших и равных элементов исходнмоу
    for (size_t i = begin; i <= end; ++i) {
        if (compare(array[i], mainMedian)) less++;
        else if (compare(mainMedian, array[i])) greater++;
        else equally++;
    }

    if ( k >= less + 1 && k <= less + equally)
        return mainMedian;
    else if (k <= less)
        return orderStatistic(array, k, begin, begin + less - 1, compare);
    else
        return orderStatistic(array, k - less - equally, end - greater + 1, end, compare);
}

#endif //ORDERSTATISTIC_ORDERSTATISTIC_H
