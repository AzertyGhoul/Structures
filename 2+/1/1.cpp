#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int length = 10000;

void bubleSort(int array[])
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            std::swap(array[i], array[j]);
            i++;
        }
    }

    std::swap(array[i], array[high]);
    return i;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void bucketSort(int array[])
{
    int bucketHelp[length];
}

void firstMethod(int *array)
{
    auto start = std::chrono::steady_clock::now();
    bubleSort(array);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\nelapsed time on buble sort: " << elapsed_seconds.count() << "s\n";
}

void secondMethod(int *arrayQuick)
{
    auto start1 = std::chrono::steady_clock::now();
    quickSort(arrayQuick, 0, length);
    auto end1 = std::chrono::steady_clock::now();
    auto elapsed_seconds1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "\nelapsed time on quick sort: " << elapsed_seconds1.count() << "s\n";
}

int main()
{
    srand(time(NULL));

    int array[length];
    int arrayQuick[length];

    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % 10 + 1;
    }
    firstMethod(array);

    for (int i = 0; i < length; i++)
    {
        arrayQuick[i] = rand() % 10 + 1;
    }

    secondMethod(arrayQuick);
}