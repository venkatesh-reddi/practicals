#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
void push();
void pop();
void peek();
void display();
void main()
{
int ch;
while(1)
{
 printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
 printf("\nenter your choice :");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 peek();
 break;
 case 4:
 display();
 break;
 case 5:
 exit(0);
 default:
 printf("Invalid choice");
 }
}
}
void push()
{
int val;
printf("enter element to push ");
scanf("%d",&val);
if(top==SIZE-1)
{
 printf("stack is full");
}
else
{
 top++;
 stack[top]=val;
 printf("element pushed ");
}
}
void pop()
{
if(top==-1)
{
 printf("stack is empty");
}
else
{
 printf("popped element is %d",stack[top]);
 top--;
}
}
void peek()
{
if(top==-1)
{
 printf("stack is empty");
}
else
{
 printf("top element is %d",stack[top]);
}
}
void display()
{
int i;
if(top==-1)
{
 printf("stack is empty");
}
else
{
 printf("elements in stack");
 for(i=top;i>=0;i--)
 {
 printf("\n%d",stack[i]);
 }
}
}