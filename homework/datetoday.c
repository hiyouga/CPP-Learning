#include<stdio.h>
int main()
{
    int y,m,d,i;
    scanf("%d %d %d",&y,&m,&d);
    int * p;
    if(y%400==0||(y%4==0&&y%100!=0)){
        int m2d[12]={31,29,31,30,31,30,31,31,30,31,30,31};
        p = m2d;
    }else{
        int m2d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        p = m2d;
    }
    for(i=0;i<m-1;i++){
        d+=p[i];
    }
    printf("%d\n",d);
    return 0;
}
