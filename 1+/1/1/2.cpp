#include <iostream>

int size = 0;
int array[5];

void addItem(int *array, int &size)
{
    int value = 0;

    std::cout << "\nEnter value : ";
    std::cin >> value;

    for (int i = size; i > 0; i--)
    {
        array[i] = array[i - 1];
    }

    array[0] = value;
    size += 1;
}

void delItem(int *array, int &size)
{
    if (size == 0)
    {
        std::cout << "\nStack is empty\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = array[i + 1];
    }

    size--;
}

void top(int *array, int &size)
{
    std::cout << "\nTop : " << array[0] << "\n";
}

void menu()
{
    std::cout << "\nStack : ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    int option = 0;
    std::cout << "\n\n1) Add element\n";
    std::cout << "2) Delete element\n";
    std::cout << "3) Top\n";
    std::cout << "4) Exit\n";

    std::cout << "\nEnter menu option : ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        addItem(array, size);
        menu();
        break;

    case 2:
        delItem(array, size);
        menu();
        break;

    case 3:
        top(array, size);
        menu();
        break;

    case 4:
        break;

    default:
        std::cout << "\nIncorect\n";
        menu();
        break;
    }
};

int main()
{
    menu();
}