#include <stdio.h>

int isloop(int x)
{
    int s = 0, b = x;
    while(x > 0){
        s *= 10;
        s += x%10;
        x /= 10;
    }
    return s == b;
}

int main()
{
    int a, b, i;
    scanf("%d %d", &a, &b);
    for(i = a; i <= b; i++){
        if(isloop(i)) printf("%d\n", i);
    }
    return 0;
}
