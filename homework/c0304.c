#include<stdio.h>
int div(int x,int n,int i)
{
    if(x==n){
        return i;
    }else if(x<n){
        return 0;
    }else{
        div(x-n,n+1,i+1);
    }
}
int main()
{
    int x,n,max_n=0,m=0;
    scanf("%d",&x);
    int p;
    for(p=1;p<x;p++){
        n=div(x,p,1);
        if(n){
            max_n=n;
            m=p;
            break;
        }
        /*if(n>max_n){
            max_n=n;
            m=p;
        }*/
    }
    if(max_n==0){
        printf("No Answer\n");
    }else{
        int q;
        printf("%d=",x);
        for(q=0;q<max_n;q++){
            printf("%d",q+m);
            if(q!=max_n-1)printf("+");
        }
    }
    //printf("%d %d",max_n,m);
}
