#include <iostream>
#include <string>

struct Some
{
    std::string secondName;
    std::string address;
};

int main()
{

    Some array[] = {
        {"NEKRASOV", "NET"},
        {"POCH", "EPOPV"},
        {"CINCHOPA", "DAB"},
        {"AXE", "FURION"},
    };

    std::string targetSecondName;

    std::cout << "\nEnter Name : ";
    getline(std::cin, targetSecondName);

    for (int i = 0; i < 4; i++)
    {
        if (array[i].secondName == targetSecondName)
        {
            std::cout << "\nSecond name : " << array[i].secondName;
            std::cout << "\nAddress : " << array[i].address;
            break;
        }
    }
}
