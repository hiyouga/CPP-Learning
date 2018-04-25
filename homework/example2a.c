#include <stdio.h>

double dabs(double k)
{
    if(k < 0) return -k;
    return k;
}

int main()
{
    int n = 0;
    double a, k, pre, nwt;
    scanf("%lf %lf", &a, &k);
    nwt = a / 2;
    do{
        pre = nwt;
        nwt = 0.5 * (pre + a / pre);
        n++;
    }while(dabs(pre - nwt) >= k);
    printf("%d\n", n);
    return 0;
}
