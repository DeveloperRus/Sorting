# Быстрая сортировка
**`Здесь представлена рандомизированная версия данной сортировки`**
> В файле [main.cpp](./main.cpp) вы можете увидеть
  применение данной сортировки в контексте задачи [Task.pdf](./Task.pdf)

Несмотря на медленную работу в худшем случае **(O(n)=n<sup><small>2</small></sup>)**, этот алгоритм на практике зачастую оказывается 
оптимальным благодаря тому, что что среднее время работы составляет **O(n\*Lg(n))** и имеет малые по величине 
постоянные множители в сложности алгоритма. Также преимуществом является то, что сортировка не использует дополнительную память, 
кроме рекурсивных вызовов.  

### Описание работы

Быстрая сортировка основана на парадигме "разделяй и властвуй". Выбирается опора сортировки (элемент, с которым будет 
происходить сравнение). Дальше массив, путем переупорядочивания его элементов, 
разбивается на два подмассива (возможно пустых). Каждый элемент левого подмассива не превышает опору сортировки, а каждый
элемент правого массива не меньше этой опоры. Данная процедура выполняется рекурсивно для подмассивов. В результате массив
будет отсортирован.   
Опору сортировки можно выбирать произвольно, но если привязаться к конкретному положению (конец, середина, начало...), 
то данную сортировку можно будет сломать и она перестанет быть эффективной. `См. наихудшее разбиение`

### Оценка производительности:
1. **Наихудшее разбиение**   
Наихудшее поведение алгоритма имеет место в том случае, когда рекурсивное разбиение 
массива порождает массивы с **n-1** элементами и с **1** элементом. В таком случае 
**T(n)=T(n-1)+O(n)**, в результате чего получается арифмитическая прогрессия и,
следовательно, **O(n)=n<sup><small>2</small></sup>**  
Если нам известно, как реализован алгоритм сортировки, то мы можем задать такую последовательность элементов,
что алгоритм будет работать с наихудшим поведением (кроме случая рандомизированной версии). Один из таких
примеров: [AntiQuickSort](../AntiQuickSort).
2. **Наилучшее разбиение**  
В самом благоприятном случае массив рекурсивно разбивается на равные подмассивы и время работы быстрой сортировки 
описывается уравнением **T(n)=2\*T(n/2)+O(n)**, следовательно общая сложность **O(n\*Lg(n))**.
3. **Среднее время выполнения**  
В ассимптотическом пределе поведение алгоритма в среднем случае намного ближе к наилучшему случаю.

### Улучшенная быстрая сортировка
1. **Быстрая сортировка с разделением на три части**  
Когда в сортируемом массиве имеется множество повторяющихся ключей предыдущие реализации быстрой сортировки можно 
существенно улучшить. Например массив, который состоит из равных ключей, вовсе не нуждается в дальнейшей сортировке, 
однако предыдущие реализации продолжают процесс разделения, подвергая обработке все более мелкие подмассивы, 
независимо от того, насколько большим является исходный файл.
2. **Параллельная сортировка**  
Еще одной оптимизацией является параллельная сортировка на основе быстрой. Пусть, исходный набор данных расположен на 
первом процессоре, с него начинается работа алгоритма. Затем исходный массив окажется разделенным на две части, меньшая 
из которых передастся другому свободному процессору, большая останется на исходном для дальнейшей обработки. Далее обе 
части опять будут разделены и опять на двух исходных останутся большие части, а меньшие отправятся другим процессорам.
3. **Introsort**  
Для предотвращения ухудшения времени работы быстрой сортировки до **O(n<sup><small>2</small></sup>)** при неудачных 
входных данных, также можно использовать алгоритм сортировки Introsort. Он использует быструю сортировку и переключается 
на пирамидальную сортировку, когда глубина рекурсии превысит некоторый заранее установленный уровень (например, логарифм 
от числа сортируемых элементов).



