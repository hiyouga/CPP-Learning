// C calculator BY hoshi_hiyouga AT 2017-11-10 03:22 LAST MODIFIED IN 2017-11-21 23:11
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
}stk[MAXSIZE], ep[MAXSIZE];//stk:����� ep:���ʽ

npt init(npt p)//��ʼ��ջ
{
    p -> type = 0;
    return p;
}

npt push(npt temp,npt p)//ѹջ
{
    memcpy(++p, temp, sizeof(struct node));
    return p;
}

/*npt pop(npt p)//��ջ ʵ���ϲ�����--p���_��
{
    return --p;
}*/

void prt(npt p)//��ӡջ ������
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

int isp(char k)//��Ԫ�ص����ȼ�
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

int icp(char k)//��Ԫ�ص����ȼ�
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
    struct node op,*ptr,*pte;//op:����
    ptr = init(stk);//������ջ
    pte = init(ep);//���ʽջ
    int i;
    char t, x[64];
    t = getchar();
    while(t != EOF && t != '\n'){//!��׺ת��׺
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
        if(isdigit(x[0])) {//����
            op.type = INT;
            op.data = atoi(x);
            pte = push(&op,pte);
        } else {//�����
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
    while(pte->type != 0){//!��ת���ʽ
        ptr = push(pte,ptr);
        pop(pte);
    }
    while(ptr->type != 0){//!�����׺���ʽ
        struct node ans;
        ans.type = INT;
        if(ptr->type == CHAR){//�����
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
        }else{//����
            pte = push(ptr, pte);
        }
        pop(ptr);
        //prt(ptr);printf("\n");prt(pte);printf("\n");
    }
    printf("%d\n",pte->data);
    return 0;
}
