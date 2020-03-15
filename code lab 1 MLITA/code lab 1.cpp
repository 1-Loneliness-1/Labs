#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
using namespace std;

static int kqs = 1, kbs = 0, kss = 0, qsswaps = 0, bsswaps = 0, ssswaps = 0,qssrawn = 0, bssrawn = 0, sssrawn = 0;

void qsort(int b, int e, int c[])
{

    int i = b, j = e;//Индексы первого и последнего элементов массива
    int pivot = c[(i + j) / 2]; // Опорным элементом для примера возьмём средний
    while (i <= j)//Выполнение сортировки прерывается при пересечении сходящихся элементов
    {
        while (c[i] < pivot)//Поиск элемента не подходящего для левой части массива
            i++;
        while (c[j] > pivot)//Поиск элемента не подходящего для правой части массива
            j--;
        if (i <= j)
        {
            swap(c[i], c[j]);
            qssrawn++;
            qsswaps++;
            i++;
            j--;
        }
        else
            qssrawn++;
    }
    if (j = i - 1)
        kqs++;
    //Рекурсивный вызов функции при необходимости если осталось что сортировать(сортировка завершается либо при переполнении памяти, 
    //выделенной под адреса возврата , либо когда каждый из подмассивов будет представлять собой массив длины один, то есть будет отсортирован)
    if (b < j)
        qsort(b, j, c);
    if (e > i)
        qsort(i, e, c);
}
//Сортировка пузырьком
void boublesort(int n, int c[])
{
    int i = 0, j = n - 1;
    while (i != j)
    {
        while (i < j)
        {
            if (c[i] > c[i + 1])
            {
                swap(c[i], c[i + 1]);
                bsswaps++;
                bssrawn++;
            }
            else
                bssrawn++;
            i++;
        }
        i = 0;
        j--;
        kbs++;
    }
}

void selectsort(int n, int c[])
{
    int count = 0, min = c[count], index = 0, flag = 0;
    while (count < n - 1)
    {
        for (int i = count; i < n; i++)
        {
            if (c[i] < min)
            {
                index = i;
                min = c[i];
                flag = 1;
                sssrawn++;
            }
            else
                sssrawn++;
        }
        if (flag == 1)
        {
            swap(c[count], c[index]);
            ssswaps++;
        }
        count++;
        min = c[count];
        index = count;
        flag = 0;
        kss++;
    }
}

int main()
{
    using Time = std::chrono::time_point<std::chrono::steady_clock>;
    using Diff = std::chrono::microseconds;
    //Объявление и инициализация переменных для работы программы
    ofstream f;//Создание переменной для записи и последующего чтения
    f.open("input.txt");
    if (!f.fail())
    {
        std::cout << "Enter size of array: ";
        int n;
        std::cin >> n;
        int* a = new int[n];
        int* b = new int[n];
        int* c = new int[n];
        int k = 0;
        //Генерация случайных чисел и запись их в файл
        for (int i = 0; i < n; i++, k++)
        {
            f << rand() % 100 << " ";
        }
        f.close();
        //Открытие файла в режиме чтения и занесение чисел из файла в массив
        FILE* f1;
        f1 = fopen("input.txt", "r");
        for (int i = 0; i < n; i++)
        {
            fscanf(f1, "%d", &a[i]);
            b[i] = a[i];
            c[i] = a[i];
        }
        fclose(f1);
        std::cout << "Random massive from file:\n";
        for (int i = 0; i < n; i++)
            std::cout << a[i] << " ";
        Time t1 = std::chrono::steady_clock::now();
        boublesort(n, a);//Количество проходов по массиву во время выполнения алгоритма сортировки пузырьком
        Time t2 = std::chrono::steady_clock::now();
        Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);
        //Вывод отсортированного массива на экран
        std::cout << "\nRandom massive after bubble sort:\n";
        for (int i = 0; i < n; i++)
        {
            std::cout << a[i] << " ";
        }
        //Сортировка выбором
        Time t3 = std::chrono::steady_clock::now();
        selectsort(n, b);
        Time t4 = std::chrono::steady_clock::now();
        Diff diff1 = std::chrono::duration_cast<Diff>(t4 - t3);
        //Вывод массива, отсортированного при помощи метода выбора
        std::cout << "\nRandom massive after select sort:\n";
        for (int i = 0; i < n; i++)
            std::cout << b[i] << " ";
        //Сортировка массива методом быстрой сортировки
        Time t5 = std::chrono::steady_clock::now();
        qsort(0, n - 1, c);
        Time t6 = std::chrono::steady_clock::now();
        Diff diff2 = std::chrono::duration_cast<Diff>(t6 - t5);
        //Вывод массива, отсортированного при помощи быстрой сортировки
        std::cout << "\nArray after quick sort:\n";
        for (int i = 0; i < n; i++)
            std::cout << c[i] << " ";
        std::cout << "\n";
        //Вывод статистики
        std::cout << "----------BUBLE SORT----------\n";
        std::cout << "Operating time: " << diff.count() << " ms\n";
        std::cout << "Number of permutations: " << bsswaps << "\n";
        std::cout << "Number of comparisons: " << bssrawn << "\n";
        std::cout << "Number of passes on the array: " << kbs << "\n------------------------------\n";
        std::cout << "---------SELECT  SORT---------\n";
        std::cout << "Operating time: " << diff1.count() << " ms\n";
        std::cout << "Number of permutations: " << ssswaps << "\n";
        std::cout << "Number of comparisons: " << sssrawn << "\n";
        std::cout << "Number of passes on the array: " << kss << "\n------------------------------\n";
        std::cout << "----------QUICK SORT----------\n";
        std::cout << "Operating time: " << diff2.count() << " ms\n";
        std::cout << "Number of permutations: " << qsswaps << "\n";
        std::cout << "Number of comparisons: " << qssrawn << "\n";
        std::cout << "Number of passes on the array: " << kqs << "\n------------------------------\n";
        delete[] a;
        delete[] b;
        delete[] c;
    } 
    else
        std::cout << "File input.txt not open. Please check file in directory.\n";
    system("pause");
    return 0;
}

