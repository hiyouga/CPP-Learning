#include <stdio.h>
#include <malloc.h>
#define MAXN 105

typedef struct node
{
    int t;
    struct node * nxt;
}que, * qep;

qep head;

void push(int k)
{
    qep q = head, p = (qep)malloc(sizeof(que));
    while(q->nxt != NULL){
        q = q->nxt;
    }
    p -> nxt = NULL;
    p -> t = k;
    q -> nxt = p;
}

void pop()
{
    qep p = head -> nxt;
    head -> nxt = p -> nxt;
    free(p);
}

int find(int k)
{
    qep q = head;
    while(q != NULL){
        if(q->t == k)
            return 1;
        q = q -> nxt;
    }
    return 0;
}

void prt()
{
    qep q = head;
    while(q != NULL){
        printf("*que*%d\n", q->t);
        q = q -> nxt;
    }
}

int main()
{
    int i, m, n, k = 0, s = 0, d;
    head = (qep)malloc(sizeof(que));
    head -> t = -1;
    head -> nxt = NULL;
    scanf("%d %d", &m, &n);
    for(i = 0; i < n; i++){
        scanf("%d", &d);
        if(k < m){
            if(!find(d)){
                push(d);
                s++, k++;
            }
        }else{
            if(!find(d)){
                pop();
                push(d);
                s++;
            }
        }
        //prt();
    }
    printf("%d\n", s);
    return 0;
}
