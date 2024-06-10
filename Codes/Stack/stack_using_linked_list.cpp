#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;

    Node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int x)
    {
        // 3->2->1
        Node *new_node = new Node(x);
        new_node->link = top;
        top = new_node;
        // return top;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        Node *temp = top;
        top = temp->link;
        cout << temp->data << " has been popped." << endl;
        delete temp;
        // 1->2->3->4->5
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        Node *temp = top;
        cout << "The stack elements are:  ";
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    cout << "How many data you want to push: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data to be pushed: ";
        int p;
        cin >> p;
        s.push(p);
    }
    s.display();
    s.pop();
    return 0;
}