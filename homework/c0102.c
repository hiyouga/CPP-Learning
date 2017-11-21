#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n>999||n<100){
        printf("-1\n");
    }else{
        n=n%10*100+n/10%10*10+n/100;
        printf("%d",n);
    }
    return 0;
}
