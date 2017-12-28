/*
 * 不！想！写！了！
 * 参见example1c.c
*/
//C calculator BY hoshi_hiyouga AT 2017-11-10 03:22 LAST MODIFIED IN 2017-11-21 23:11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 500
#define INT 1
#define CHAR 2
#define pop(x) --x
#define isop(x) x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='='

typedef struct node * npt;

struct node {
    int type;//0:blank 1:int 2:char
    int data;
}stk[MAXSIZE], ep[MAXSIZE];//stk:运算符 ep:表达式

npt init(npt p)//初始化栈
{
    p -> type = 0;
    return p;
}

npt push(npt temp,npt p)//压栈
{
    memcpy(++p, temp, sizeof(struct node));
    return p;
}

/*npt pop(npt p)//弹栈 实际上不就是--p嘛→_→
{
    return --p;
}*/

void prt(npt p)//打印栈 调试用
{
    while(p -> type != 0){
        if(p -> type == INT){
            printf("%d ",p->data);
        }else if(p->type == CHAR){
            printf("%c ",p->data);
        }
        p--;
    }
}

int isp(char k)//旧元素的优先级
{
    switch(k){
    case '+':
        return 4;
    case '-':
        return 4;
    case '*':
        return 6;
    case '/':
        return 6;
    case '(':
        return 2;
    case ')':
        return 8;
    default:
        return 0;
    }
}

int icp(char k)//新元素的优先级
{
    switch(k){
    case '+':
        return 3;
    case '-':
        return 3;
    case '*':
        return 5;
    case '/':
        return 5;
    case '(':
        return 7;
    case ')':
        return 2;
    default:
        return 0;
    }
}

int main()
{
    struct node op,*ptr,*pte;//op:输入
    ptr = init(stk);//操作符栈
    pte = init(ep);//表达式栈
    int i;
    char t, x[64];
    t = getchar();
    while(t != EOF && t != '\n'){//!中缀转后缀
        i = 0;
        if(isdigit(t)){
            while(isdigit(t)){
                x[i++] = t;
                t = getchar();
            }
            x[i] = '\0';
        }else if(isop(t)){
            x[0] = t;
            x[1] = '\0';
            t=getchar();
        }else{
            t=getchar();
            continue;
        }
        if(isdigit(x[0])) {//数字
            op.type = INT;
            op.data = atoi(x);
            pte = push(&op,pte);
        } else {//运算符
            op.type = CHAR;
            op.data = x[0];
            if(ptr->type == 0) {
                ptr = push(&op,ptr);
            } else {
                if(op.data == ')') {
                    while(ptr->data != '(') {
                        pte = push(ptr,pte);
                        pop(ptr);
                    }
                    pop(ptr);
                }else{
                    while((isp(ptr->data) >= icp(op.data)) && ptr->type != 0){
                        pte = push(ptr,pte);
                        pop(ptr);
                    }
                    ptr = push(&op,ptr);
                }
            }
        }
    }
    //prt(ptr);printf("\n");prt(pte);printf("\n");
    while(pte->type != 0){//!翻转表达式
        ptr = push(pte,ptr);
        pop(pte);
    }
    while(ptr->type != 0){//!计算后缀表达式
        struct node ans;
        ans.type = INT;
        if(ptr->type == CHAR){//运算符
            int b = pte->data;
            pop(pte);
            int a = pte->data;
            pop(pte);
            switch(ptr->data){
                case '+':
                    ans.data = a+b;break;
                case '-':
                    ans.data = a-b;break;
                case '*':
                    ans.data = a*b;break;
                case '/':
                    ans.data = a/b;break;
            }
            pte = push(&ans, pte);
        }else{//数字
            pte = push(ptr, pte);
        }
        pop(ptr);
        //prt(ptr);printf("\n");prt(pte);printf("\n");
    }
    printf("%d\n",pte->data);
    return 0;
}
