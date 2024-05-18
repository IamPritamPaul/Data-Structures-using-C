#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *add_at_beg(struct node *, int);
struct node *add_at_end(struct node *, int);
struct node *create_list(struct node *);
void search(struct node *, int);
void display(struct node *);

int main()
{
    int n, data, item;
    struct node *start = NULL;
    while (1)
    {
        printf("\n\n1. create list\n");
        printf("2. display list\n");
        printf("3. Count the number of Nodes in the List.\n");
        printf("4. Search an element in the List.\n");
        printf("5. add at begining\n");
        printf("6. add at end\n");
        printf("7. add before a node\n");
        printf("8. add after a node\n");
        printf("9. delete a node\n");
        printf("10.quit\n");
        printf("enter your choice : \n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            start = NULL;
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            // printf("\nThe number of nodes in the linked list is: %d\n", count_nodes(start));
            break;
        case 4:
            printf("enter the element to be searched : ");
            scanf("%d", &data);
            search(start, data);
            break;
        case 5:
            printf("enter the element to be inserted : ");
            scanf("%d", &data);
            start = add_at_beg(start, data);
            break;
        case 6:
            printf("enter the element to be inserted : ");
            scanf("%d", &data);
            start = add_at_end(start, data);
            break;
        case 7:
            // printf("enter the element to be inserted : ");
            // scanf("%d",&data);
            // printf("enter the element before which it willbe added: ");
            // scanf("%d",&item);
            // start=add_before(start,item,data);
            break;
        case 8:
            // printf("enter the element to be inserted : ");
            // scanf("%d",&data);
            // printf("enter the element after which it willbe added: ");
            // scanf("%d",&item);
            // start=add_after(start,item,data);
            break;
        case 9:
            // printf("enter the element tobreak; be deleted : ");
            // scanf("%d",&item);
            // start=delet(start,item);
            break;
        case 10:
            exit(1);
        default:
            printf("wrong choice!! enter a valid number : ");
        }
    }
    return 0;
}

struct node *add_at_beg(struct node *start, int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = data;
    p->prev = NULL;
    p->next = start;
    if (start != NULL)
        start->prev = p;
    start = p;
    return start;
};

struct node *add_at_end(struct node *start, int data)
{
    struct node *p, *x;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = data;
    x = start;
    while (x->next != NULL)
    {
        x = x->next;
    }
    x->next = p;
    p->next = NULL;
    p->prev = x;
    return start;
}

struct node *create_list(struct node *start)
{
    int data, n;
    printf("enter the number of nodes : ");
    scanf("%d", &n);
    // start = NULL;
    if (n == 0)
    {
        printf("Please start again!\nYou have not created an empty list.\n");
        return start;
    }
    printf("enter the element to be inserted : ");
    scanf("%d", &data);
    start = add_at_beg(start, data);
    for (int i = 2; i <= n; i++)
    {
        printf("enter the value of the element : ");
        scanf("%d", &data);
        start = add_at_end(start, data);
    }
    return start;
};
void search(struct node *start, int data)
{
    struct node *p = start;
    int position = 1;
    while (p != NULL)
    {
        if (p->info == data)
        {
            printf("the entered data is in position %d\n", position);
            return;
        }
        p = p->next;
        position++;
    }
    printf("not found");
}

void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("list is empty\n");
        return;
    }
    p = start;
    printf("list is :\n");
    while (p != NULL)
    {
        printf("%d\t", p->info);
        p = p->next;
    }
    printf("\n");
}