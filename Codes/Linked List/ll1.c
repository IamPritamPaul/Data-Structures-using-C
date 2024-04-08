#include <stdio.h>
#include <stdlib.h>

/*
1. traversal
2. searching an element
3. insertion
    a) beginning
    b) end
    c) after any node
    d) before a node
    e) at any position
    f) between 2 nodes
4) delete
5) creation of linked list
6) reversal
*/

struct node
{
    int data;
    struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
int count_nodes(struct node *start);
int search_node(struct node *start, int item);
struct node *add_at_empty(struct node *start, int item);
struct node *add_at_beg(struct node *start, int item);
struct node *add_at_end(struct node *start, int item);
struct node *add_before(struct node *start, int item, int n);
struct node *add_after(struct node *start, int item, int n);

int main()
{
    struct node *start = NULL;
    while (1)
    {
        int choice, search, item, n;
        printf("\n1. Create List.\n");
        printf("2. Display List.\n");
        printf("3. Count the number of Nodes in the List.\n");
        printf("4. Search an element in the List.\n");
        printf("5. Add to empty List.\n");
        printf("6. Add to the beginning of the List.\n");
        printf("7. Add to the end of the List.\n");
        printf("8. Add Before a Node.\n");
        printf("9. Add after a Node.\n");
        printf("10. Add between two Nodes.\n");
        printf("11. Add at any position Node.\n");
        printf("12. Delete.\n");
        printf("13. Reverse the list.\n");
        printf("14. Exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("\nThe number of nodes in the linked list is: %d\n", count_nodes(start));
            break;
        case 4:
            printf("\nEnter the element to be searched: ");
            scanf("%d", &search);
            int pos = search_node(start, search);
            if (pos != 0)
            {
                printf("Element found at %d position.\n", pos);
            }
            else
            {
                printf("\nElement is not in the List.\n");
            }
            break;
        case 5:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &item);
            start = add_at_empty(start, item);
            break;
        case 6:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &item);
            start = add_at_beg(start, item);
            break;
        case 7:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &item);
            start = add_at_end(start, item);
            break;
        case 8:
            if (start == NULL)
            {
                printf("List is empty.\n");
                break;
            }
            printf("Enter the element before which you want to insert: ");
            scanf("%d", &n);
            if (search_node(start, n))
            {
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                start = add_before(start, item, n);
            }
            else
            {
                printf("Element is not in the list.\n");
            }
            break;
        case 9:
            if (start == NULL)
            {
                printf("List is empty.\n");
                break;
            }
            printf("Enter the element after which you want to insert: ");
            scanf("%d", &n);
            if (search_node(start, n))
            {
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                start = add_after(start, item, n);
            }
            else
            {
                printf("Element is not in the list.\n");
            }
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            exit(0);
            break;
        default:
            printf("Invalid Input.\n\n");
        }
    }
}

struct node *create_list(struct node *start)
{
    int n, i, item;
    printf("\nHow many nodes you want to insert: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
    {
        return start;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &item);
    start = add_at_empty(start, item);
    for (int i = 1; i < n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        start = add_at_end(start, item);
    }
    return start;
}

void display(struct node *start)
{
    struct node *ptr = start;
    if (ptr == NULL)
    {
        printf("\nThe list is empty.\n");
        return;
    }
    printf("\nThe list is:\t");
    while (ptr) /*  != NULL */
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
}

struct node *add_at_empty(struct node *start, int item)
{
    if (start)
    { /*!=NULL*/
        printf("\nAdd at empty is not possible as the linked list is not empty now.\n");
        return start;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nNo memory has been allcoated.\n");
        return start;
    }
    temp->data = item;
    start = temp;
    start->link = NULL;
    return start;
}

struct node *add_at_beg(struct node *start, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = start;
    start = temp;
    return start;
}

struct node *add_at_end(struct node *start, int item)
{
    struct node *p = start;
    while (p->link)
    {
        p = p->link;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    p->link = temp;
    temp->data = item;
    temp->link = NULL;
    return start;
}

int count_nodes(struct node *start)
{
    int count = 0;
    struct node *p = start;
    while (p)
    {
        count++;
        p = p->link;
    }
    return count;
}

int search_node(struct node *start, int search)
{
    struct node *p = start;
    int pos = 1;
    while (p)
    {
        if (search == p->data)
        {
            // printf("Element found at %d position.\n", pos);
            return pos;
        }
        pos++;
        p = p->link;
    }
    // printf("\nElement is not in the List.\n");
    return 0;
}

struct node *add_before(struct node *start, int item, int n)
{
    struct node *p = start;
    if (p->data == n)
    {
        start = add_at_beg(start, item);
        return start;
    }
    while (p->link != NULL)
    {
        if (p->link->data == n)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = item;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
    return start;
}

struct node *add_after(struct node *start, int item, int n)
{
    struct node *p = start;
    while (p != NULL)
    {
        if (p->data == n)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = item;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
    return start;
}