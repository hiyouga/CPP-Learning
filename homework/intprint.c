#include<stdio.h>
int main()
{
    char x[6];
    int i=0;
    gets(x);
    while(x[i]!='\0'){
        i++;
    }
    printf("%d\n",i);
    puts(x);
    while(i>=0){
        printf("%c",x[i-1]);
        i--;
    }
    return 0;
}
