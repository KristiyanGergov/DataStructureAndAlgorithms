##Алгоритми за сортиране

Бавни - bubble, selection, insertion

Бързи - merge, quick

Специфични - count

# Свойста на сортиране Bubble Sort, Selection Sort, Insertion Sort

- Def: Stable Sort

example: before - 1 2 3a 8 3b 5
         after -  1 2 3a 3b 5 8

- Def: 

    In-Place         vs          Out-Place
-Не изплзва доп.         Използва доп. памет
памет    

- Def: Time Complexity (worst case), Space Complexity

- Def: Number of Comparisons

- Def: Number of Swaps

- Def: Adaptivity (спрямо данните се адаптира и се повлиява ефективноста на алгоритъма)
Ако има разлика между worst/best case

- Def: Online (след сортиране не се променя при добавяне на нов елемент)
Bubble Sort - не е
Insertion Sort - e



##Task: Ако са зададени лист от обекти които имплементират < може ли да се сортира листа
Example: A < B, B < C, C < A
 -не защото 
    1. Ако А <= B и B <= A, то А = B (Антисиметричност)
    2. Ако А <= B и B <= С то А <=С (транзитивност)
    3. Всяко А<=А (Рефлективност)


##Bubble Sort
- метод на мехурчето 
- easy to write

e.g. : (1) (2) (4) (2) (4) (5)

да си го представим вертикално => колкото по голяма тежест има ще се опита да изплува нагоре

(1)      (5)     
(2)      (4)
(4)      (4)
(2)      (2)
(4)      (2)
(5)      (1)

Базова имплементация:

void bubbleSort(int* array, int length) 
{
    for(int i = 0; i < length; i++)
    {
        for(int c = 0; c < length - 1;c++)
        {
            if(array[c] > array[c + 1])
            {
                swap(array[c], array[c + 1]);
            }
        }
    }
}

 - Time complexity: O(length^2)
 - Space complexity: O(1) = const
 - Stable: 1
 - Number of Comparisons: length^2
 - Number of Swaps: length^2
 - Online: 0
 - In-Place: 1
 - Out-Place: 0
 - Adaptive: 1 


Оптимизирана имплементация:

void bubbleSort(int* array, int length) 
{
    bool flag = false;
    for(int i = 0; i < length; i++)
    {
        for(int c = 0; c < length - i - 1;c++)
        {
            if(array[c] > array[c + 1])
            {
                swap(array[c], array[c + 1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}


##Selection Sort

Базова имплементация:

void selectionSort(int * array){
    for(int i = 0; i < p; i++){
        int idx = i;
        for(int c = i + 1; c < p; c++){
            if(array[c] < array[idx]>)
            idx = c;
        }
        swap(array[i], array[idx]);
    }
}

3 2 8 7 5

-Time complexity: O(p^2)
-Space complexity: O(1) = const
-Stable: 1
-Number of Comparisons: p^2
-Number of Swaps: p
-Online: 0
-In-Place: 1
-Out-Place: 0
-Adaptive: 1

##Insertion Sort

array = { 2, 1, 3, 4, 1, 5 }

i = 1) 
1 2

i = 2) 
1 2 3

i = 3) 
1 2 3 4

i = 4) 
1 2 3 1 4
1 2 1 3 4
1 1 2 3 4

i = 5)
1 1 2 3 4 5


Базова имплементация:

void insertionSort(int * array, int n){

    for(int i =1; i < n; i++){
        for(int idx = i; idx > 0 && array[idx] < array[idx -1]; idx--){
            swap(array[idx], array[idx -1]);
        }
    }
}

-Time complexity: O(n^2)
-Space complexity: O(1) = const
-Stable: 1
-Number of Comparisons: n^2
-Number of Swaps: n^2
-Online: 1
-In-Place: 1
-Out-Place: 0
-Adaptive: 1


## Merge sort

arr1 = { 5, 3, 2, 1, 8, 9 }

arr2 = { 3, 9, 7, 2, 6}

arr3 = { 1, 2, 3 }

arr4 = { 4, 5, 6 }

1) 1 < 4?
2) 2 < 4?
3) 3 < 4?

arr_3_4_sorted = { 1, 2, 3, 4, 5, 6 }


{5, 1, 7, 3, 2, 8, 6, 4}

{5, 1, 7, 3}    |    {2, 8, 6, 4}

{5, 1} | {7, 3} | {2, 8} | {6, 4}

{5} | {1} | {7} | {3} | {2} | {8} | {6} | {4}

{1, 5} | {3, 7} | {2, 8} | {4, 6}

{1, 3, 5, 7} | {2, 4, 6, 8}

{1, 2, 3, 4, 5, 6, 7, 8}


-Time complexity: O(n*logn)
-Space complexity: O(n)
-Stable: 1
-Number of Comparisons: n
-Number of Swaps: n
-Online: 1
-In-Place: 0
-Out-Place: 1
-Adaptive: 0
-Parallel: 1
-External: 1


##TimSort

{ 5, 2, 8, 9, 10, 6, 3, 7 }



-Time complexity: O(n*logn) (worst case) O(n) (best case)
-Space complexity: O(n)
-Stable: 1
-Number of Comparisons: n
-Number of Swaps: n
-Online: 1
-In-Place: 0
-Out-Place: 1
-Adaptive: 0
-Parallel: 1
-External: 1


