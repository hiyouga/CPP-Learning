#include <stdio.h>
#include <stdlib.h>
#define MAXN 999

typedef struct{
    int a;
    int n;
} Node;

int cmp(const void * p, const void * q)
{
    return ((*(Node*)p).n < (*(Node*)q).n)?1:-1;
}

int main()
{
    int i, j, p = 0, q = 0, r = 0;
    Node temp, pre[MAXN], lst[MAXN], nwt[MAXN];
    char c;
    temp.a = -1, temp.n = -1;
    while((scanf("%d%d%c", &pre[p].a, &pre[p].n, &c)) && (c != '\n')) p++;
    while((scanf("%d%d%c", &lst[q].a, &lst[q].n, &c)) && (c != '\n')) q++;
    for(i = 0; i <= p; i++){
        for(j = 0; j <= q; j++){
            nwt[r].a = pre[i].a * lst[j].a;
            nwt[r].n = pre[i].n + lst[j].n;
            r++;
        }
    }
    qsort(nwt, r, sizeof(Node), cmp);
    for(i = 0; i < r; i++){
        if(temp.n == nwt[i].n){
            temp.a += nwt[i].a;
        }else{
            if(i != 0) printf("%d %d ", temp.a, temp.n);
            temp.a = nwt[i].a;
            temp.n = nwt[i].n;
        }
    }
    printf("%d %d", temp.a, temp.n);
    return 0;
}
