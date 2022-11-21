#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

struct student
{
    char fam[20] = "\0";
    char dr[20] = "\0";
    char hob1[12] = "\0";
    char hob2[12] = "\0";
    char hob3[12] = "\0";
    char hob4[12] = "\0";
};

int heshFunction(char *inputString)
{
    return unsigned char(inputString[0]) * 8;
}

void addToFile(std::string pathToFile, student &input)
{
    std::fstream file;
    file.open(pathToFile, std::ios::in | std::ios::binary);
    if (!file.is_open())
        std::cout << "Error open file\n";
    else
    {
        student tmp;
        int hesh = heshFunction(input.fam);
        hesh = (hesh - (64 * 8)) / 8; // ����� ��������� �������� � ���� (������� � ���� A - 65)
        file.seekg(hesh * sizeof(student));
        file.read((char *)&tmp, sizeof(student));
        if (tmp.fam[0] == input.fam[0])
        {
            std::string pathToFile = std::string() + input.fam[0] + ".dat";
            std::ofstream outputFile(pathToFile, std::ios::app | std::ios::binary);
            if (!outputFile.is_open())
                std::cout << "Error open file\n";
            else
            {
                outputFile.write((char *)&input, sizeof(student));
                outputFile.close();
            }
            file.close();
        }
        else
        {
            file.close();
            file.open(pathToFile, std::ios::in | std::ios::out | std::ios::binary);
            if (!file.is_open())
                std::cout << "Error open file\n";
            else
            {
                file.seekg(hesh * sizeof(student));
                file.write((char *)&input, sizeof(student));
                file.close();
            }
        }
    }
}

bool printFile(std::string pathToFile, int counter = 0)
{
    std::ifstream inputFile(pathToFile);
    if (!inputFile.is_open())
        return false;
    else
    {
        student tmp;
        inputFile.seekg(0, std::ios::end);
        int size = inputFile.tellg() / sizeof(student);
        inputFile.seekg(0);
        for (int i = 0; i < size; i++)
        {
            inputFile.read((char *)&tmp, sizeof(student));
            if (tmp.fam[0] != '\0')
            {
                std::cout << tmp.fam << '\n';
                std::cout << tmp.dr << '\n';
                std::cout << tmp.hob1 << '\n';
                std::cout << tmp.hob2 << '\n';
                std::cout << tmp.hob3 << '\n';
                std::cout << tmp.hob4 << '\n';
                std::cout << "==================================================\n";
                if (counter == 0)
                {
                    std::string pathToFile = std::string() + tmp.fam[0] + ".dat";
                    printFile(pathToFile, 1);
                }
            }
        }
        inputFile.close();
        return true;
    }
}

bool stringEqual(char *one, char *two, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (one[i] != two[i])
            return false;
    }
    return true;
}

bool findInFile(std::string pathToFile, char *find, int counter = 0)
{
    std::ifstream inputFile(pathToFile);
    if (!inputFile.is_open())
        return false;
    else
    {
        student tmp;
        inputFile.seekg(0, std::ios::end);
        int size = inputFile.tellg() / sizeof(student);
        inputFile.seekg(0);
        for (int i = 0; i < size; i++)
        {
            inputFile.read((char *)&tmp, sizeof(student));
            if (tmp.fam[0] != '\0')
            {
                if (stringEqual(tmp.fam, find, 20))
                {
                    std::cout << tmp.fam << '\n';
                    std::cout << tmp.dr << '\n';
                    std::cout << tmp.hob1 << '\n';
                    std::cout << tmp.hob2 << '\n';
                    std::cout << tmp.hob3 << '\n';
                    std::cout << tmp.hob4 << '\n';
                    std::cout << "==================================================\n";
                }
                if (counter == 0)
                {
                    std::string pathToFile = std::string() + tmp.fam[0] + ".dat";
                    findInFile(pathToFile, find, 1);
                }
            }
        }
        inputFile.close();
        return true;
    }
}

int main()
{
    system("chcp 1251");
    system("cls");
    char menu = '0';
    student tmp;
    char find[20] = "\0";
    std::string pathToFile = "students.dat";
    //==================================================
    // ��������� ���� �� ������, ���� ��� ������
    std::ofstream outputFile(pathToFile);
    if (!outputFile.is_open())
        std::cout << "Error open file\n";
    else
        outputFile.close();
    //==================================================
    while (menu != '4')
    {
        std::cout << "1. �������� ������\n";
        std::cout << "2. ����� ������ �� ���� Fam\n";
        std::cout << "3. �������� ���� ���������\n";
        std::cout << "4. �����\n";
        menu = _getch();
        system("cls");
        switch (menu)
        {
        case '1':
            std::cout << "������� �������: ";
            std::cin >> tmp.fam;
            std::cout << "������� ���� ��������: ";
            std::cin >> tmp.dr;
            std::cout << "������� �����1: ";
            std::cin >> tmp.hob1;
            std::cout << "������� �����2: ";
            ;
            std::cin >> tmp.hob2;
            std::cout << "������� �����3: ";
            std::cin >> tmp.hob3;
            std::cout << "������� �����4: ";
            std::cin >> tmp.hob4;
            addToFile(pathToFile, tmp);
            system("cls");
            break;
        case '2':
            std::cin >> find;
            findInFile(pathToFile, find);
            system("pause");
            system("cls");
            break;
        case '3':
            printFile(pathToFile);
            system("pause");
            system("cls");
            break;
        }
    }
    //==================================================
    return 0;
}