#include <fstream>
#include <iostream>
#include <string>

void addItem()
{
    std::fstream file;
    file.open("Num.dat", std::ios::out | std::ios::binary);

    if (file.is_open())
    {
        int numbers;
        int size = 0;

        std::cout << "\nEnter how much numbers you want to add in file : ";
        std::cin >> size;
        std::cout << "\n";

        for (int i = 0; i < size; i++)
        {
            std::cout << "Enter numbers : ";
            std::cin >> numbers;

            if (numbers > 200)
            {
                file.seekp(sizeof(int) * numbers);
                file.write(reinterpret_cast<char *>(&numbers), sizeof(int));
            }
            else
            {
                std::cout << "\nIncorect\n\n";
            }
        }
    }

    file.close();

    std::fstream tmpfile;

    file.open("Num.dat", std::ios::in | std::ios::binary);
    tmpfile.open("tmp.dat", std::ios::app | std::ios::binary);
    if (tmpfile.is_open())
    {
        int numbers = 0;
        while (file.read(reinterpret_cast<char *>(&numbers), sizeof(int)))
        {
            if (numbers != 0)
            {
                tmpfile.write(reinterpret_cast<char *>(&numbers), sizeof(int));
            }
        }
    };

    file.close();
    tmpfile.close();

    remove("Num.dat");
    rename("tmp.dat", "Num.dat");
}

void printItem()
{
    std::fstream file;
    int numbers;

    std::cout << "\n";

    file.open("Num.dat", std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        std::cout << "Numbers from file : ";
        while (file.read(reinterpret_cast<char *>(&numbers), sizeof(int)))
        {
            std::cout << numbers << " ";
        }
    }

    else
    {
        std::cout << "Incorect";
    }

    std::cout << "\n";
}

void deleteFile()
{
    remove("Num.dat");
}

void menu()
{
    int option = 0;

    std::cout << "\n1) Add number\n";
    std::cout << "2) Print numbers\n";
    std::cout << "3) Delete file\n";
    std::cout << "4) Exit\n";

    std::cout << "\nEnter menu option : ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        addItem();
        menu();
        break;

    case 2:
        printItem();
        menu();
        break;

    case 3:
        deleteFile();
        menu();
        break;

    case 4:
        break;

    default:
        std::cout << "\nIncorect";
        menu();
        break;
    }
}

int main()
{
    menu();
}