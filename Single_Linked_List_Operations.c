#include <stdio.h>
#include <stdlib.h>

struct slinklist
{
    int data;
    struct slinklist *next;
};
typedef struct slinklist node;
node *start = NULL;
int menu()
{
    int ch;
    printf("\n1.Create a list");
    printf("\n----------------");
    printf("\n2.Insert at beginning");
    printf("\n3.Insert at end");
    printf("\n4.Insert at position");
    printf("\n----------------");
    printf("\n5.Delete from beginning");
    printf("\n6.Delete from end");
    printf("\n7.Delete from position");
    printf("\n----------------");
    printf("\n8.Display");
    printf("\n9.Count nodes");
    printf("\n10.Exit");
    printf("\n----------------");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

node *create_node()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

int count_nodes(node *start)
{
    int count = 0;
    node *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void create_list(int n)
{
    int i;
    node *newnode, *temp;
    for(i = 0; i < n; i++)
    {
        newnode = create_node();
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void traverse()
{
    node *temp = start;
    printf("The linked list is: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insert_at_beg()
{
    node *newnode = create_node();
    newnode->next = start;
    start = newnode;
}

void insert_at_end()
{
    node *newnode = create_node();
    node *temp = start;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_at_pos()
{
    int pos, i;
    node *newnode = create_node();
    node *temp = start;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        newnode->next = start;
        start = newnode;
    }
    else if(pos == count_nodes(start) + 1)
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    else if(pos > 1 && pos <= count_nodes(start))
    {
        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Invalid position");
    }
}

void delete_from_beg()
{
    node *temp = start;
    if(start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        start = start->next;
        free(temp);
    }
}

void delete_from_end()
{
    node *temp = start;
    if(start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_from_pos()
{
    int pos, i;
    node *temp = start;
    node *temp1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        start = start->next;
        free(temp);
    }
    else if(pos == count_nodes(start))
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    else if(pos > 1 && pos < count_nodes(start))
    {
        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
    else
    {
        printf("Invalid position");
    }
}

void main()
{
    int ch, n;
    while(1)
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create_list(n);
                break;
            case 2:
                insert_at_beg();
                break;
            case 3:
                insert_at_end();
                break;
            case 4:
                insert_at_pos();
                break;
            case 5:
                delete_from_beg();
                break;
            case 6:
                delete_from_end();
                break;
            case 7:
                delete_from_pos();
                break;
            case 8:
                traverse();
                break;
            case 9:
                printf("Number of nodes: %d", count_nodes(start));
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}