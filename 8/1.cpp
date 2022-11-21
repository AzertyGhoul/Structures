#include <iostream>

class Node
{
  public:
    int number;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data)
    {
        number = data;
    }
};

class Tree
{
  public:
    Node *root = NULL;

    Node *insertion(Node *node, int value){

    };

    void TournamentSorted(int array[], int size)
    {

        root = insertion(root, array[0]);

        for (int i = 1; i < size; i++)
        {
            root = insertion(root, array[i]);
        }
    };
};

int main()
{
    Tree tree;

    int array[] = {54, 31, 72, 62, 5, 95, 7, 64, 59, 87, 63, 64};

    int size = sizeof(array) / sizeof(array[0]);

    tree.TournamentSorted(array, size);
}