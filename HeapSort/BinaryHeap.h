#ifndef HEAPSORT_BINARYHEAP_H
#define HEAPSORT_BINARYHEAP_H

#include <functional>
#include <fstream>

/**
 * Двоичная куча на массиве
 * @tparam Type тип хранимых элементов
 * @tparam Compare компаратор для сравнения элементов
 */
template <class Type, class Compare = std::less<Type>>
class BinaryHeap {
public:
    /**
     * Конструктор с параметрами
     * @param array исходный массив
     * @param size размер массива
     */
    BinaryHeap(Type * array, const size_t size) : size(size) {
        this->data = new Type[size];

        for (size_t i = 0; i < size; ++i) {
            this->data[i] = array[i];
        }
        buildHeap();
    }

    /**
     * Деструктор
     */
    ~BinaryHeap() {
        delete [] data;
    }

    /**
     * Heap sort
     * @param output поток для вывода результата
     */
    void sort(std::ofstream& output) {
        size_t size = this->size;

        for (size_t i = size - 1; i > 0; --i) {
            std::swap(data[0], data[i]);
            this->size--;
            heapify(0);
        }

        this->size = size;

        for (size_t i = 0; i < this->size; ++i) {
            output << data[i] << " ";
        }
        buildHeap(); // Восстанавливаем кучу
    }

private:
    Type * data;
    Compare compare;
    size_t size;

    /**
     * Восстановление свойств кучи
     */
    void buildHeap() {
        for (long long int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    /**
     * Восстановление основного свойства кучи для дереве с вершиной i
     * при условии, что оба поддерева ему удовлетворяют.
     * @param index вершина
     */
    void heapify(size_t index) {
        Type left = 2 * index + 1;
        Type right = 2 * index + 2;
        Type max = index;

        if (left < size && compare(data[max], data[left]))
            max = left;
        if (right < size && compare(data[max], data[right]))
            max = right;
        if (max != index) {
            std::swap(data[index], data[max]);
            heapify(max);
        }
    }
};

#endif //HEAPSORT_BINARYHEAP_H
