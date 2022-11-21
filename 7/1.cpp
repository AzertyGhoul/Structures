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
    Node *head = NULL;
    Node *tail = NULL;

    void binaryTreeToDLL(Node *root)
    {

        if (root == NULL)
            return;

        binaryTreeToDLL(root->left);

        if (head == NULL)
        {
            head = root;
            tail = root;
        }
        else
        {
            tail->right = root;
            root->left = tail;
            tail = root;
        }

        binaryTreeToDLL(root->right);
    };

    Node *insertion(Node *node, int value)
    {
        if (node == NULL)
            return new Node(value);

        if (node->number > value)
        {
            node->left = insertion(node->left, value);
        }
        else if (node->number < value)
        {
            node->right = insertion(node->right, value);
        }

        return node;
    }

    void sortedArray(int array[], int size)
    {

        root = insertion(root, array[0]);

        for (int i = 1; i < size; i++)
        {
            root = insertion(root, array[i]);
        }
    };

    void inOrder(class Node *node)
    {
        if (node == NULL)
            return;

        inOrder(node->left);
        std::cout << node->number << " ";
        inOrder(node->right);
    };

    void preOrder(Node *node)
    {
        if (node == NULL)
            return;

        std::cout << node->number << " ";
        preOrder(node->left);
        preOrder(node->right);
    };

    void postOrder(Node *node)
    {
        if (node == NULL)
            return;

        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->number << " ";
    };

    void printList()
    {
        Node *current = head;
        while (current != NULL)
        {
            std::cout << current->number << " ";
            current = current->right;
        }
    }
};

int main()
{
    Tree tree;

    int array[] = {54, 31, 72, 62, 5, 95, 7, 64, 59, 87, 63, 64};

    int size = sizeof(array) / sizeof(array[0]);

    tree.sortedArray(array, size);

    tree.binaryTreeToDLL(tree.root);

    tree.printList();
}