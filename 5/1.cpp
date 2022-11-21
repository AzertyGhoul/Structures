#include <fstream>
#include <iostream>
#include <conio.h>

int hash(char *inputString)
{
    return ((unsigned char(inputString[0]) * 20) + (unsigned char(inputString[0])) - 21) * (sizeof(char) * 50);
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
    FILE *file = fopen(path, "r+t");
    char string[50];
    int hashCount = 0;
    std::cout << "\nEnter name : ";
    std::cin.ignore();
    std::cin.get(string, 50);

    int i = 0;

    while (string[i])
    {
        char letter = tolower(string[i]);
        string[i] = letter;
        i++;
    }

    while (true)
    {
        char tmpString[50] = {'\0'};

        fseek(file, (hash(string) + hashCount), SEEK_SET);
        fgets(tmpString, sizeof(char) * 50, file);

        if (tmpString[0] != '\0')
        {
            hashCount++;
        }
        else
        {
            break;
        }
    }

    fseek(file, (hash(string) + hashCount), SEEK_SET);
    fputs(string, file);
    fclose(file);
}

void searchItem(char *path)
{
    std::fstream file;
    char targetName[50];
    char items[50];

    std::cout << "\nEnter target name : ";
    std::cin.ignore();
    std::cin.get(targetName, 50);

    file.open("mybd.txt", std::ios::in);
    file.seekg(hash(targetName));
    file.read(items, (sizeof(char) * 50));

    if (equal(items, targetName))
    {
        std::cout << "\nYes\n";
    }
    else
    {
        std::cout << "\nNo\n";
    }
};

void print(char *path)
{

    char items[50];
    std::fstream file;

    std::cout << "\nText from file : ";

    file.open(path, std::ios::in);

    while (!file.eof())
    {
        file.read(items, (sizeof(char) * 50));
        if (items[0] != '\0')
            std::cout << items << " ";
    }

    std::cout << "\n";

    file.close();
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
    system("chcp 1251");
    char path[] = "mybd.txt";
    FILE *f = fopen(path, "wt");
    if (f == NULL)
    {
        std::cout << "KRING";
    }

    menu(path);
}