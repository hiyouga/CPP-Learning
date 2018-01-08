#include <stdio.h>
int main()
{
 int i,n,sum,mul,if1;
 int forAndwhile[100];
 
 sum=0;mul=1;
 scanf("%d",&n);
 for(i=0;i<n;i++)
  scanf("%d",&forAndwhile[i]);
 for(i=0;i<n;i++)sum+=forAndwhile[i];for(i=0;i<n;i++)mul*=forAndwhile[i];

 i=1;
 if1=forAndwhile[0];
 while (i<n)
 {
  if(if1<forAndwhile[i])
   if1=forAndwhile[i];
 }
 printf("The max of for and while is :%d\n",if1);
 return 0;
}