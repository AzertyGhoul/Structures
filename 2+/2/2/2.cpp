#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

void bubleSort(std::string fr[])
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 999 - i; j++)
        {
            if (fr[j] > fr[j + 1])
            {
                std::string tmp = fr[j];
                fr[j] = fr[j + 1];
                fr[j + 1] = tmp;
            }
        }
    }
}

void linear(std::string fr[])
{
    std::string targetLetter;

    std::cout << "Enter target letter : ";
    std::cin >> targetLetter;

    for (int i = 0; i < 1000; i++)
    {
        if (fr[i] == targetLetter)
        {
            std::cout << i;
            break;
        }
    }
}

void binary(std::string fr[])
{
    std::string targetLetter;

    std::cout << "\nEnter target letter : ";
    std::cin.ignore();
    getline(std::cin, targetLetter);

    bool check = false;
    int l = 999;
    int r = 0;
    int mid = 0;
    int counter = 0;

    while (!check)
    {
        mid = (l + r) / 2;

        if (fr[mid] < targetLetter)
        {
            r = mid;
        }

        if (fr[mid] > targetLetter)
        {
            l = mid;
        }

        if (fr[mid] == targetLetter)
        {
            std::cout << counter;
            check = true;
        }

        counter += 1;
    }
}

int main()
{
    srand(time(NULL));

    std::string fr[1000];

    for (int i = 0; i < 1000;)
    {
        char letter = rand() % 127;
        if (isalnum(letter))
        {
            fr[i] = letter;
            ++i;
        }
    }

    bubleSort(fr);

    linear(fr);

    binary(fr);
}