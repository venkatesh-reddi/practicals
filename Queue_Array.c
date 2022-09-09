#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int queue[SIZE];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void display();
void main()
{
int ch;
while(1)
{
 printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
 printf("\nenter your choice :");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 enqueue();
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 exit(0);
 default:
 printf("Invalid choice");
 }
}
}
void enqueue()
{
int val;
printf("enter element to insert ");
scanf("%d",&val);
if(rear==SIZE-1)
{
 printf("queue is full");
}
else if(front==-1&&rear==-1)
{
 front++;
 rear++;
 queue[rear]=val;
 printf("element inserted ");
}
else
{
 rear++;
 queue[rear]=val;
 printf("element inserted");
}
}
void dequeue()
{
int i;
if(front==-1&&rear==-1)
{
 printf("queue is empty");
}
else if(front==rear)
{
 front=-1;
 rear=-1;
}
else
{
 for(i=front;i<rear;i++)
 {
 queue[i]=queue[i+1];
 }
 rear--;
 printf("element deleted");
}
}
void display()
{
int i;
if(front==-1&&rear==-1)
{
 printf("queue is empty");
}
else
{
 printf("elements in queue ");
 for(i=front;i<=rear;i++)
 {
 printf("\t%d",queue[i]);
 }
}
}