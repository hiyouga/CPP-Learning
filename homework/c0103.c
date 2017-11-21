#include<stdio.h>
int main()
{
    char a,b,c;
    b = getchar();
    a=b-1;c=b+1;
    printf("%c %c %c\n%d %d %d",a,b,c,a,b,c);
    return 0;
}
