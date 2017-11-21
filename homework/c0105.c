#include<stdio.h>
void put(c){
    printf("%d ",c);
}
int main()
{
    int n;
    scanf("%d",&n);
    put(n/10);
    n%=10;
    put(n/5);
    n%=5;
    put(n/2);
    put(n%2);
}
