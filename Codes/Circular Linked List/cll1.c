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

// struct node *create_list(struct node *);
void display(struct node *);
int count_nodes(struct node *);
// int search_node(struct node *, int);
struct node *add_at_empty(struct node *, int);
struct node *add_at_beg(struct node *, int);
struct node *add_at_end(struct node *, int);
// struct node *add_before(struct node *, int, int);
// struct node *add_after(struct node *, int, int);
// struct node *add_in_between(struct node *, int, int, int);

int main()
{
    struct node *last = NULL;
    while (1)
    {
        int choice, search, item, n, a, b;
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
            // last = create_list(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
            printf("\nThe number of nodes in the linked list is: %d\n", count_nodes(last));
            break;
        case 4:
            // printf("\nEnter the element to be searched: ");
            // scanf("%d", &search);
            // int pos = search_node(last, search);
            // if (pos != 0)
            // {
            //     printf("Element found at %d position.\n", pos);
            // }
            // else
            // {
            //     printf("\nElement is not in the List.\n");
            // }
            break;
        case 5:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &item);
            last = add_at_empty(last, item);
            break;
        case 6:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &item);
            last = add_at_beg(last, item);
            break;
        case 7:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &item);
            last = add_at_end(last, item);
            break;
        case 8:
            // if (last == NULL)
            // {
            //     printf("List is empty.\n");
            //     break;
            // }
            // printf("Enter the element before which you want to insert: ");
            // scanf("%d", &n);
            // if (search_node(last, n))
            // {
            //     printf("Enter the element to be inserted: ");
            //     scanf("%d", &item);
            //     last = add_before(last, item, n);
            // }
            // else
            // {
            //     printf("Element is not in the list.\n");
            // }
            break;
        case 9:
            // if (last == NULL)
            // {
            //     printf("List is empty.\n");
            //     break;
            // }
            // printf("Enter the element after which you want to insert: ");
            // scanf("%d", &n);
            // if (search_node(last, n))
            // {
            //     printf("Enter the element to be inserted: ");
            //     scanf("%d", &item);
            //     last = add_after(last, item, n);
            // }
            // else
            // {
            //     printf("Element is not in the list.\n");
            // }
            break;
        case 10:
            // printf("Enter the nodes between which you want to insert: ");
            // scanf("%d%d", &a, &b);
            // printf("Enter the data you want to insert: ");
            // scanf("%d", &item);
            // last = add_in_between(last, a, b, item);
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            exit(0);
            break;
        default:
            printf("Invalid Input.\n\n");
        }
    }
}

void display(struct node *last)
{
    if (last == NULL)
    {
        printf("List is Empty.\n");
        return;
    }
    struct node *p = last->link;
    printf("\nThe list is:\t");
    do
    {
        printf("%d\t", p->data);
        p = p->link;
    } while (p != last->link);
    printf("\n");
    return;
}

struct node *add_at_empty(struct node *last, int item)
{
    if (last != NULL)
    {
        printf("\nList is not empty.\n");
        return last;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = item;
        last = temp;
        last->link = last;
        return last;
    }
}

struct node *add_at_beg(struct node *last, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = last->link;
    last->link = temp;
    return last;
}

struct node *add_at_end(struct node *last, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = last->link;
    last->link = temp;
    last = temp;
    return last;
}

int count_nodes(struct node *last)
{
    int count = 0;
    struct node *p = last->link;
    do
    {
        count++;
        p = p->link;
    } while (p != last->link);
    return count;
}