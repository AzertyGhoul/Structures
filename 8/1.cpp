#include <iostream>

class Node
{
    int number;
    Node *left;
    Node *right;

    Node(int data)
    {
        number = data;
    }
};

class Tree
{
public:
    Node *root = NULL;

    void fillTree(int array[], int size)
    {

        for (int i = 0; i < size; i++)
        {
        }
    }

    void tournament(int array[], int size)
    {
        fillTree(array, size);
    }
};

int main()
{
    int array[] = {54, 31, 72, 62, 5, 95, 7, 64, 59, 87, 63, 64};
    const int size = sizeof(array) / sizeof(array[0]);

    Tree tree;

    tree.tournament(array, size);
}