#include <iostream>

const int maxV = 122;
const int minV = 97;

int hash(char secondName)
{
    return ((((secondName - 96) * 20) + (secondName - 96 - 21)) * sizeof(char));
}

int main()
{
    system("chcp 1251");
    srand(time(NULL));

    char letter = rand() % (maxV - minV + 1) + minV;

    int keys[526];

    for (int i = 0; i <= 525; i++)
    {
        keys[i] = 0;
    }

    for (int i = 0; i < 100000; i++)
    {
        char letter = rand() % (maxV - minV + 1) + minV;
        int numberOfAddress = hash(letter);
        keys[numberOfAddress]++;
    }

    for (int i = 0; i <= 525; i++)
    {
        if (keys[i] != 0)
        {
            std::cout << keys[i] << " ";
        }
    }
}