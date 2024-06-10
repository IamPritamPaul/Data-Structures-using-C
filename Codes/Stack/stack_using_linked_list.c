#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;

int is_empty();
// int is_full();
void display();
void push(int item);
int pop();
int peek();

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n\n1. push\n");
        printf("2. pop\n");
        printf("3. display the first element\n");
        printf("4. display all element\n");
        printf("5. quit\n");
        printf("enter your choices : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            printf("poped item is %d ", item);
            break;
        case 3:
            printf("the first element is %d  ", peek());
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Enter a valid input");
        }
    }
    return 0;
}
void push(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = start;
    start = temp;
}
void display()
{
    if (start == NULL)
    {
        printf("Stack is empty!!");
    }
    while (start != NULL)
    {
        printf("%d\t", start->data);
        start = start->link;
    }
}
int pop()
{
    struct node *temp;
    int item;
    temp = start;
    item = temp->data;
    start = start->link;
    free(temp);
    return item;
}
int peek()
{
    int item;
    item = start->data;
    return item;
}
int is_empty()
{
    if (start == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}