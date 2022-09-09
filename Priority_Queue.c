#include <stdio.h>
#include <stdlib.h>

#define MAX 10
void insert(int);
void delete(int);
void create();
void check(int);
void display_pqueue();
int pri_que[MAX];
int front, rear;

void main()
{
    int n, ch;

    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
    create();
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Input the element for adding in queue : ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf("Input the element for deleting from queue : ");
            scanf("%d", &n);
            delete(n);
            break;
        case 3:
            display_pqueue();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}

void create()
{
    front = rear = -1;
}

void insert(int data)
{
    if (rear >= MAX - 1)
    {
        printf("Queue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}   

void check(int data)
{
    int i,j;

    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

void delete(int data)
{
    int i;

    if ((front == -1) || (front > rear))
    {
        printf("Queue underflow no elements to delete");
        return;
    }

    for (i = front; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }

            pri_que[i] = -99;
            rear--;

            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("Element %d not found in queue to delete", data);
}

void display_pqueue()
{
    int i;

    if ((front == -1) || (front > rear))
    {
        printf("Queue is empty");
        return;
    }

    for (i = front; i <= rear; i++)
        printf("%d ", pri_que[i]);
}
