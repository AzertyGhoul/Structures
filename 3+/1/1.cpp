#include <iostream>
#include <string>

struct Node
{
    std::string secondName;
    std::string faculty;
    std::string course;
    Node *next;
};

class List
{

  public:
    Node *head = NULL;
    int length = 0;

    void add(std::string secondName, std::string faculty, std::string course)
    {
        Node *firstNode = new Node({secondName, faculty, course});

        if (head == NULL)
        {
            head = firstNode;
        }
        else
        {
            Node *newNode = head;

            while (newNode->next != NULL)
            {
                newNode = newNode->next;
            }

            newNode->next = firstNode;
        }

        length += 1;
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
            head = head->next;
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

            current->next = current->next->next;
            length--;
        }
    }

    void print()
    {
        Node *listHead = head;

        std::cout << "\n\nList : ";
        while (listHead != NULL)
        {
            std::cout << listHead->secondName << " ";
            listHead = listHead->next;
        }
    }

    void contain()
    {
        Node *listHead = head;
        std::string targetName;

        std::cout << "\n\nEnter target name : ";
        std::cin >> targetName;

        while (listHead != NULL)
        {
            if (listHead->secondName == targetName)
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

    std::string secondName;
    std::string faculty;
    std::string course;

    list.add("Nekrasov", "faculty1", "3102");
    list.add("Boris", "faculty2", "3102");
    list.add("Artur", "faculty3", "3102");
    list.add("Kochkin", "faculty4", "3102");
    list.add("Kiss", "faculty5", "3102");

    list.print();
    list.remove(3);
    list.print();
    list.remove(4);
    list.print();
    list.remove(4);

    list.contain();

    std::cout << "\n\n";
}