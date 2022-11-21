#include <fstream>
#include <iostream>
#include <string>

struct city
{
    std::string name;
    int population;
    int square;
};

void addItem()
{
    struct city city17;
    std::fstream file;

    std::cout << "\nEnter name of city : ";
    std::cin >> city17.name;

    std::cout << "Enter population of city : ";
    std::cin >> city17.population;

    std::cout << "Enter square of city : ";
    std::cin >> city17.square;

    file.open("records.dat", std::ios::app | std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<char *>(&city17), sizeof(city));
        file.close();
    }
    else
    {
        std::cout << "\nIncorect\n";
    }
}

void delItem()
{
    std::fstream file;
    std::fstream tmpfile;
    struct city city17;

    std::string targetName;

    std::cout << "\nEnter Name To Delete: ";
    std::cin.ignore();
    getline(std::cin, targetName);

    file.open("records.dat", std::ios::in | std::ios::binary);
    tmpfile.open("tmp.dat", std::ios::app | std::ios::binary);
    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(reinterpret_cast<char *>(&city17), sizeof(city));
            if (city17.name == targetName)
            {
                continue;
            }
            else
            {
                tmpfile.write(reinterpret_cast<char *>(&city17), sizeof(city));
            }
        }

        file.close();
        tmpfile.close();
    }

    remove("records.dat");
    rename("tmp.dat", "records.dat");
}

void contain()
{
    std::fstream file;
    struct city city17;
    bool containCheck = false;

    std::string targetName;
    int targetPopulation;
    int targetSquare;

    std::cout << "\nEnter Name : ";
    std::cin.ignore();
    getline(std::cin, targetName);

    std::cout << "Enter Population : ";
    std::cin >> targetPopulation;

    std::cout << "Enter Square : ";
    std::cin >> targetSquare;

    file.open("records.dat", std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(reinterpret_cast<char *>(&city17), sizeof(city));
            if (city17.name == targetName && city17.population == targetPopulation && city17.square == targetSquare)
            {
                containCheck = true;
            }
        }
        file.close();
    }
    else
    {
        std::cout << "\nIncorect\n";
    }

    if (containCheck)
    {
        std::cout << "\nYes\n";
    }
    else
    {
        std::cout << "\nNo\n";
    }
}

void printStruct()
{
    std::fstream file;
    struct city city17;

    file.open("records.dat", std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        while (file.read(reinterpret_cast<char *>(&city17), sizeof(city)))
        {
            std::cout << "\nName : " << city17.name << std::endl;
            std::cout << "Population : " << city17.population << std::endl;
            std::cout << "Square : " << city17.square << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "\nIncorect\n";
    }
}

void menu()
{
    int option = 0;
    std::cout << "\n1) Add element\n";
    std::cout << "2) Delete element\n";
    std::cout << "3) Contain\n";
    std::cout << "4) Print struct\n";
    std::cout << "5) Exit\n";

    std::cout << "\nEnter menu option : ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        addItem();
        menu();
        break;

    case 2:
        delItem();
        menu();
        break;

    case 3:
        contain();
        menu();
        break;

    case 4:
        printStruct();
        menu();
        break;

    case 5:
        break;

    default:
        std::cout << "Incorect";
        menu();
        break;
    }
}

int main()
{
    menu();
}