#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    float s,x;
    scanf("%d %d %d",&a,&b,&c);
    s=(a+b+c)/2.0;
    x=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("%.3f",x);
    return 0;
}
