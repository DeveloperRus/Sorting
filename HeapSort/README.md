# Сортировка кучей

**Сложность: O(n\*Lg(n))** 

Двоичная куча представляет собой полное бинарное дерево, для которого выполняется основное свойство кучи: приоритет 
каждой вершины больше приоритетов её потомков.

Двоичную кучу удобно хранить в виде одномерного массива, причем левый потомок вершины с индексом **i** имеет индекс 
**2\*i+1**, а правый **2\*i+2**. Корень дерева – элемент с индексом **0**. Высота двоичной кучи равна высоте дерева, 
то есть **Lg(n)**.

В данной реализации для хранения элементов кучи используется одномерный массив. 

В [main.cpp](./main.cpp) представлено применение кучи в контесте задачи [Task](./Task.pdf)
