#include <iostream>
#include <string>

int size = 0;
std::string array[5];

void addItem(std::string *array, int &size)
{
    std::string value;

    std::cout << "\nEnter value : ";
    std::cin.ignore();
    getline(std::cin, value);

    array[size] = value;
    size += 1;
};

void delItem(std::string *array, int &size)
{
    if (size == 0)
    {
        std::cout << "\nQueue is empty\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = array[i + 1];
    }
};

void length(std::string *array, int &size)
{
    std::cout << "\nlength : " << size << "\n";
};

void menu()
{
    std::cout << "\nQueue : ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    int option = 0;
    std::cout << "\n\n1) Add element\n";
    std::cout << "2) Delete element\n";
    std::cout << "3) length\n";
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
        length(array, size);
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