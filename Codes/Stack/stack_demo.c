#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// global declarations
int stack_arr[SIZE];
int top = -1;

// functions
int pop();
void push(int data);
int peek();
int is_empty();
int is_full();
void display();

// main function
int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1. Push.\n2. Pop\n3. Top Element\n4. Traversal of the Stack\n5. Quit.\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be pushed into the stack: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            // item=pop();
            printf("The popped item is: %d", pop());
            break;
        case 3:
            // item=peek();
            printf("The peek element of the stack is: %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Input.\n");
        }
    }
}

int is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full()
{
    if (top == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (is_full())
    {
        printf("Stack Overflow.\n");
        return;
    }
    top++;
    stack_arr[top] = data;
    return;
}

int pop()
{
    int popped_element;
    if (is_empty())
    {
        printf("Stack Underflow.\n");
        exit(0);
    }
    popped_element = stack_arr[top];
    top--;
    return popped_element;
}

int peek()
{
    if (is_empty())
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    return stack_arr[top];
}

void display()
{
    if (is_empty())
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    printf("\nThe elements of the stack:  ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d  ", stack_arr[i]);
    }
}