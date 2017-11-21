#include<stdio.h>
int main()
{
    int n,a,b,c,d,flag;//c=ab d=ba
    flag=0;
    scanf("%d",&n);
    for(a=1;a<10;a++){
        for(b=1;b<10;b++){
            c=10*a+b;
            d=10*b+a;
            if(c*d==n){
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
    printf("%d%d\n",a,b);
    return 0;
}
