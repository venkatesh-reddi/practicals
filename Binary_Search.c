#include<stdio.h>
void main()
{
int a[20],n,lb,ub,mid,i,ele,flag;
printf("enter size of array ");
scanf("%d",&n);
printf("enter elements in sorted order ");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
printf("enter element to search ");
scanf("%d",&ele);
lb=0;
ub=n-1;
flag=0;
while(lb<=ub)
{
 mid=(lb+ub)/2;
 if(a[mid]==ele)
 {
 printf("Element found at index %d",mid);
 flag=1;
 break;
 }
 else if(ele>a[mid])
 {
 lb=mid+1;
 }
 else
 {
 ub=mid-1;
 }
}
if(flag==0)
{
 printf("element not found");
}
}