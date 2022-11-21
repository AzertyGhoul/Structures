#include <iostream>

struct Node
{
    float number;
    Node *next;
};

class Stack
{
  public:
    Node *head = NULL;

    void addItem(float number)
    {
        Node *num = new Node({number});

        if (head == NULL)
        {
            head = num;
        }
        else
        {
            Node *newNum = head;

            while (newNum->next != NULL)
            {
                newNum = newNum->next;
            }

            num->next = head;
            head = num;
        }
    }

    void printStack()
    {
        Node *stack = head;

        std::cout << "Stack : ";
        while (stack != NULL)
        {
            std::cout << stack->number << " ";
            stack = stack->next;
        }
        
    }
};

int main()
{
    Stack stack;

    stack.addItem(1);
    stack.addItem(2);
    stack.addItem(3);
    stack.addItem(4);
    stack.addItem(5);
    stack.addItem(6);
    stack.addItem(7);
    stack.addItem(8);
    stack.addItem(9);
    stack.addItem(11);

    stack.printStack();
}