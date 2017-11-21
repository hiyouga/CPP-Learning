#include<stdio.h>
int main()
{
    int a,b;
    char op;
    scanf("%d %d %c",&a,&b,&op);
    switch(op){
    case '+':
        printf("%d",a+b);
        break;
    case '-':
        printf("%d",a-b);
        break;
    case '*':
        printf("%d",a*b);
        break;
    case '/':
        if(a%b==0){
            printf("%d",a/b);
        }else{
            printf("%.2f",a*1.0/b);
        }
        break;
    }
    return 0;
}
