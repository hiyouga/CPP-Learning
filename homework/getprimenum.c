#include<stdio.h>
#include<math.h>
int is_p(int x)
{
    if(x==1) return 0;
    int k;
    for(k=2;k*k<x;k++){
        if(x%k==0) return 0;
    }
    return 1;
}
int rev(int x)
{
    int i=1,t=x,s=0;
    while(t/10!=0){
        t/=10;
        i++;
    }
    while(i>0){
        s+=x%10;
        if(i!=1) s*=10;
        x/=10;
        i--;
    }
    return s;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(is_p(n)&&is_p(rev(n))){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}
