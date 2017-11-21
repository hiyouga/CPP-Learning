#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i=2;
    while(i!=n){
        if(n%i==0){
            printf("%d ",i);
            n/=i;
        }else{
            i++;
        }
    }
    printf("%d",n);
    return 0;
}
