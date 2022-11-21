#include <fstream>
#include <iostream>

struct record
{
    std::string secondName;
    std::string name;
};

int hash(record records)
{
    int hash = 1;

    for (int i = 0; i < 2; i++)
    {
        hash += (i + 1) * (int)records.secondName[i];
    }

    return hash * sizeof(record);
}

int main()
{
    std::fstream file;
    record records;
    record records1;
    record records2;

    records = {"Pochilko", "Arsi"};
    records1 = {"Nekrasov", "Aleksei"};
    records2 = {"Melnik", "Danil"};

    file.open("record.dat", std::ios::out | std::ios::binary);
    file.seekp(hash(records));
    file.write(reinterpret_cast<char *>(&records), sizeof(record));
    file.seekp(hash(records1));
    file.write(reinterpret_cast<char *>(&records1), sizeof(record));
    file.seekp(hash(records2));
    file.write(reinterpret_cast<char *>(&records2), sizeof(record));
    file.close();

    record check;

    file.open("record.dat", std::ios::in | std::ios::binary);
    file.seekg(hash(records2));
    file.read(reinterpret_cast<char *>(&check), sizeof(record));
    std::cout << check.secondName;
    file.close();

    return 0;
}