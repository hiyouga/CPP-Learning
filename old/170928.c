#include<stdio.h>
void main() {
    int x = 10, y = 9;
    int a, b, c;
    a = (--x == y++)? --x: ++y;
    b = x++;
    c = y;
    a = b = c = 3;
    printf("%d%d%d\n",a,b,c);
}
