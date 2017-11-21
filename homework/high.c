#include<stdio.h>
int main()
{
    double n,m,s,i;
    scanf("%lf %lf",&n,&m);
    s=n;
    for(i=0;i<m-1;i++){
        n/=4;
        s+=n*2;
    }
    n/=4;
    printf("%.2f\n%.2f\n",s,n);
    return 0;
}
