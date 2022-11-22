#include <fstream>
#include <iostream>

struct company
{
    char nameCompany[20] = "\0";
    int count = 0;
};

int hash(char *secondName)
{
    int hash = (int)secondName[1] + (int)secondName[2];
    return (hash * sizeof(company));
}

bool equal(char *item, char *target)
{
    for (int i = 0; target[i] != '\0'; i++)
    {
        if (item[i] != target[i])
        {
            return false;
        }
    }

    return true;
}

void addItem(char *path)
{
    company add;

    std::fstream file;

    std::cout << "\nEnter name : ";
    std::cin.ignore();
    std::cin.get(add.nameCompany, 20);

    std::cout << "\nEnter count of employee : ";
    std::cin >> add.count;

    file.open(path, std::ios::in | std::ios::out | std::ios::binary);
    file.seekg(hash(add.nameCompany));
    file.write(reinterpret_cast<char *>(&add), sizeof(company));
    file.close();
}

void searchItem(char *path)
{
    std::fstream file;
    char targetName[20];
    company items;

    std::cout << "\nEnter target name : ";
    std::cin.ignore();
    std::cin.get(targetName, 20);

    file.open(path, std::ios::in | std::ios::binary);
    file.seekg(hash(targetName));
    file.read(reinterpret_cast<char *>(&items), (sizeof(company)));

    if (equal(items.nameCompany, targetName))
    {
        std::cout << "\nName : " << items.nameCompany << std::endl;
        std::cout << "Employee : " << items.count << "\n";
    }
    else
    {
        std::cout << "\nNo\n";
    }
};

void print(char *path)
{
    company item;
    int size = 0;
    std::fstream file;

    std::cout << "\nText from file\n";

    file.open(path, std::ios::in | std::ios::binary);

    file.seekg(0, std::ios::end);
    size = (int)file.tellg() / sizeof(company);
    file.seekg(0);

    for (int i = 0; i < size; i++)
    {
        file.read((char *)&item, sizeof(company));
        if (item.nameCompany[0] != '\0')
        {
            std::cout << "\nCompany name : " << item.nameCompany << "\n";
            std::cout << "Employee : " << item.count << "\n";
        }
    }
}

void menu(char *path)
{
    int option = 0;

    std::cout << "\n1) Add element\n";
    std::cout << "2) Search element\n";
    std::cout << "3) Print\n";
    std::cout << "4) Exit\n";

    std::cout << "\nEnter option : ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        addItem(path);
        menu(path);
        break;

    case 2:
        searchItem(path);
        menu(path);
        break;

    case 3:
        print(path);
        menu(path);
        break;

    case 4:
        break;

    default:
        std::cout << "Incorect";
        break;
    }
}

int main()
{
    char path[] = "company.dat";
    FILE *f = fopen(path, "r+b");

    menu(path);
}