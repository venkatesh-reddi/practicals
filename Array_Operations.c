#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert();
void delet();
int a[10];
int n=0;
void main()
{
int ch;
while(1)
{
 printf("\n1.create\n2.display\n3.insert\n4.delete\n5.exit");
 printf("\nenter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
    case 1:
        create();
        break;
    case 2:
        display();
        break;
    case 3:
        insert();
        break;
    case 4:
        delet();
        break;
    case 5:
        exit(0);
    default:
        printf("invalid choice");
 }
}
}
void create()
{
int i;
printf("enter size");
scanf("%d",&n);
printf("enter elements\n");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
}
void display()
{
int i;
printf("the elements in array are: ");
for(i=0;i<n;i++)
{
 printf("%d\t",a[i]);
}
}
void insert()
{
int ele,ind,i;
printf("enter element to insert ");
scanf("%d",&ele);
printf("enter index to insert ");
scanf("%d",&ind);
for(i=n-1;i>=ind;i--)
{
 a[i+1]=a[i];
}
a[ind]=ele;
n=n+1;
}
void delet()
{
int ind,i;
printf("enter index to delete");
scanf("%d",&ind);
for(i=ind;i<n;i++)
{
 a[i]=a[i+1];
}
n=n-1;
}