#include<stdio.h>
double ta(double x)
{
    if(x==1) return 1;
    x*=ta(x-1);
    return x;
}
double pl(double x)
{
    if(x==3) return 3;
    x*=pl(x-2);
    return x;
}
int main()
{
    int n=3;
    double e,a,b,t;
    scanf("%lf",&e);
    a=1;
    b=1+1/3.0;
    t=1/3.0;
    while(t*2>=e){
        a=b;
        //printf("%f %f\n",ta(n-1),pl(2*n-1));
        t=ta(n-1)*1.0/pl(2*n-1);
        b+=t;
        n++;
        //printf("%f %.7f\n",t,b*2);
    }
    printf("%d %.7f\n",n-1,b*2);
    return 0;
}
