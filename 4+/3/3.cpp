#include <iostream>
#include <string>

struct Node
{
    std::string secondName;
    Node *next;
    Node *prev;
};

class List
{
  public:
    Node *head = NULL;
    int length = 0;

    void addItem(std::string secondName)
    {
        Node *newNode = new Node({secondName});

        if (head == NULL)
        {
            head = newNode;
            length++;
        }
        else
        {
            Node *current = head;

            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
            length++;
        }
    }
    void delItem()
    {
        if (length == 1)
        {
            head = NULL;
            length--;
            return;
        }
        else
        {
            head->next->prev = NULL;
            head = head->next;
            length--;
        }
    }
    void setPower()
    {
        std::cout << "Length : " << length << "\n\n";
    }
    void printList()
    {
        Node *listHead = head;

        std::cout << "\nList : ";
        while (listHead != NULL)
        {
            std::cout << listHead->secondName;
            listHead = listHead->next;
        }
        std::cout << "\n\n";
    }
    void contain(std::string targetName)
    {
        while (head != NULL)
        {
            if (head->secondName == targetName)
            {
                std::cout << "Yes\n";
                return;
            }
            head = head->next;
        }
        std::cout << "No\n";
    }
};

int main()
{
    List list;

    std::string secondName;

    list.addItem("1");
    list.delItem();
    list.addItem("2");
    list.addItem("3");
    list.addItem("4");
    list.addItem("5");
    list.addItem("6");
    list.addItem("7");
    list.printList();
    list.setPower();
    list.contain("3");
}
