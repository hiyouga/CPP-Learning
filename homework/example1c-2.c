#include <stdio.h>

int cal(int d1, int d2, char op)
{
    switch(op){
    case '+':
        return d1 + d2;
    case '-':
        return d1 - d2;
    case '*':
        return d1 * d2;
    case '/':
        return d1 / d2;
    default:
        return -1;
    }
}
int main()
{
    int d1, d2, d3;
    char op1, op2, op3;
    if(scanf("%d %c", &d1, &op1) == 0) return -1;
    while(op1 != '='){
        if(scanf("%d %c", &d2, &op2) == 0) return -1;
        while(op2 == '*' || op2 == '/'){
            if(scanf("%d %c", &d3, &op3) == 0) return -1;
            d2 = cal(d2, d3, op2);
            op2 = op3;
        }
        d1 = cal(d1, d2, op1);
        op1 = op2;
    }
    printf("%d", d1);
    return 0;
}
