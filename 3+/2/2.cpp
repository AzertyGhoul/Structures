#include <iostream>
#include <string>

class Node
{
  public:
    std::string nameOil;
    Node *next;
    Node *prev;
};

class List
{

  public:
    Node *head = NULL;
    int length = 0;

    void add(std::string nameOil)
    {
        Node *firstNode = new Node({nameOil});

        if (head == NULL)
        {
            head = firstNode;
            length++;
        }
        else
        {
            Node *node = head;

            while (node->next != NULL)
            {
                node = node->next;
            }

            firstNode->prev = node;
            node->next = firstNode;
            length++;
        }
    }

    void remove(int index)
    {
        if (head == NULL)
        {
            std::cout << "List is empty";
            return;
        }

        if (index > length)
        {
            std::cout << "\n\nOut of index";
            return;
        }

        if (index == 1)
        {
            head->next->prev = NULL;
            head = head->next;
            length--;
        }

        if (index == length)
        {
            Node *current = head;

            int counter = 1;

            while (index > counter + 1)
            {
                current = current->next;
                counter += 1;
            }

            current->next = current->next->next;
            length--;
        }

        else
        {
            Node *current = head;

            int counter = 1;

            while (index > counter + 1)
            {
                current = current->next;
                counter += 1;
            }

            current->next->next->prev = current;
            current->next = current->next->next;
            length--;
        }
    }

    void printLeft()
    {
        Node *listHead = head;

        std::cout << "\n\nList left : ";
        while (listHead != NULL)
        {
            std::cout << listHead->nameOil << " ";
            listHead = listHead->next;
        }
    }

    void printRight()
    {
        Node *last = head;

        while (last->next != NULL)
        {
            last = last->next;
        }

        std::cout << "\n\nList right : ";
        while (last != NULL)
        {
            std::cout << last->nameOil << " ";
            last = last->prev;
        }
    }

    void contain()
    {
        Node *listHead = head;
        std::string targetNameOil;

        std::cout << "\n\nEnter target name : ";
        std::cin >> targetNameOil;

        while (listHead != NULL)
        {
            if (listHead->nameOil == targetNameOil)
            {
                std::cout << "\nYes";
                return;
            }
            listHead = listHead->next;
        }

        std::cout << "\nNo";
    }
};

int main()
{
    List list;

    list.add("Oil1");
    list.add("Oil2");
    list.add("Oil3");
    list.add("Oil4");
    list.add("Oil5");

    list.printLeft();
    list.printRight();

    list.remove(5);

    list.printLeft();
    list.printRight();

    list.contain();

    std::cout << "\n\n";
}