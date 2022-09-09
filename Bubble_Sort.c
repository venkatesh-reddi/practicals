#include<stdio.h>
void main()
{
int a[20],n,i,j,temp;
printf("enter the size of an array ");
scanf("%d",&n);
printf("enter values of an array ");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
printf("elements of an array before sorting ");
for(i=0;i<n;i++)
{
 printf("%d\t",a[i]);
}
for(i=0;i<n-1;i++)
{
 for(j=0;j<n-i-1;j++)
 {
 if(a[j]>a[j+1])
 {
 temp=a[j];
 a[j]=a[j+1];
 a[j+1]=temp;
 }
 }
}
printf("\nelements of an array after sorting ");
for(i=0;i<n;i++)
{
 printf("%d\t",a[i]);
}
}