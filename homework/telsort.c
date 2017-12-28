#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 55

typedef struct {
    char name[15];
    char tel[15];
} user;

int cmp(const void * p, const void * q)
{
    return strcmp((*(user*)p).name, (*(user*)q).name);
}

int main()
{
    int i, n;
    user bok[MAXN];
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
        scanf(" %s %s", bok[i].name, bok[i].tel);
    }
    qsort(bok, n, sizeof(user), cmp);
    for(i = 0; i < n; i++){
        printf("%12.10s%12.10s\n", bok[i].name, bok[i].tel);
    }
    return 0;
}
