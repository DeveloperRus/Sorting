#include <iostream>
#include <vector>
#include <fstream>
#include "QuickSort.h"
#include <ctime>

/**
 * Структура описывающая спортсмена
 */
struct Athlete {
    std::string country, name;
    size_t place;
};

/**
 * Функция для упорядочивания {@code Athlete} по возрастанию в быстрой сортировке
 * @param a первый спортсмен
 * @param b второй
 * @return результат сравнения
 */
bool less(const Athlete& a, const Athlete& b) {
    return a.country < b.country || (a.country == b.country && a.place < b.place);
}

int main() {
    long long int size; // Колличество спортсменов (размер массива)
    std::ifstream input("race.in");
    std::ofstream output("race.out");
    input >> size;

    auto * athletes = new Athlete[size];

    // Считывание данных с файла
    for (size_t i = 0; i < size; i++)
    {
        input >> athletes[i].country >> athletes[i].name;
        athletes[i].place = i + 1;
    }

    quickSort(athletes, 0, size - 1, less);

    // Запись результата в заданном формате
    std::string currentCountry;
    for (int i = 0; i < size; i++)
    {
        if (athletes[i].country != currentCountry)
        {
            currentCountry = athletes[i].country;
            output << "=== " << currentCountry << " ===" << std::endl;
        }
        output << athletes[i].name << std::endl;
    }

    delete [] athletes; // Очищение памяти

    return 0;
}