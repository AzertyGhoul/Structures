#include <fstream>
#include <iostream>

struct record
{
    char secondName[10] = {'\0'};
    char name[10] = {'\0'};
};

int hash(char *secondName)
{
    int hash = 0;

    hash += ((int)secondName[0] - 96) * 40;

    return hash * sizeof(record);
}

void addItem(char *path)
{
    std::fstream file;
    FILE *fileZ = fopen(path, "rb");
    int hashCount = 0;
    record check;

    std::cin.ignore();
    std::cout << "\nEnter second name : ";
    gets_s(check.secondName, 10);

    std::cout << "Enter name : ";
    gets_s(check.name, 10);

    file.open(path, std ::ios::out | std::ios::in | std::ios::binary);

    while (true)
    {
        record tmpRecord;

        fseek(fileZ, (hash(check.secondName) + hashCount), SEEK_SET);
        fgets(reinterpret_cast<char *>(&tmpRecord), sizeof(record), fileZ);

        if (tmpRecord.secondName[0] != '\0' && tmpRecord.name[0] != '\0')
            hashCount += sizeof(check);
        else
            break;
    }

    file.seekp((hash(check.secondName) + hashCount));
    file.write(reinterpret_cast<char *>(&check), sizeof(record));
    file.close();
}

void print(char *path)
{
    std::fstream file;
    record check;
    int size = 0;

    file.open(path, std::ios::in | std::ios::binary);

    file.seekg(0, std::ios::end);
    size = (int)file.tellg() / sizeof(record);
    file.seekg(0);

    for (int i = 0; i < size; i++)
    {
        file.read(reinterpret_cast<char *>(&check), sizeof(record));
        if (check.secondName[0] != '\0')
        {
            std::cout << "\nSecond name : " << check.secondName << "\n";
            std::cout << "Name : " << check.name << "\n";
        }
    }
}

void menu(char *path)
{
    int option = 0;

    std::cout << "\n1) Add element\n";
    std::cout << "2) Print\n";
    std::cout << "3) Exit\n";

    std::cout << "\nEnter option : ";
    std::cin >> option;

    switch (option)
    {
    case 1:
        addItem(path);
        menu(path);
        break;

    case 2:
        print(path);
        menu(path);
        break;

    case 3:
        break;

    default:
        std::cout << "Incorect";
        break;
    }
}

int main()
{
    char path[] = "record.dat";

    std::fstream file;

    file.open(path, std::ios::out | std::ios::binary);

    menu(path);
    return 0;
}