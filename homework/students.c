#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 55

typedef struct {
    unsigned int id;
    char name[10];
    unsigned int age;
} Stu;

int cmpa(const void * p, const void * q)
{
    return strcmp((*(Stu*)p).name, (*(Stu*)q).name);
}

int cmpb(const void * p, const void * q)
{
    return ((*(Stu*)p).age > (*(Stu*)q).age)?1:-1;
}

void prt(Stu * a, int n)
{
    int i;
    for(i = 0; i < n; i++){
        printf("%3d%6s%3d\n", a[i].id, a[i].name, a[i].age);
    }
}

int main()
{
    int i, n;
    Stu lst[MAXN];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %s %d", &lst[i].id, lst[i].name, &lst[i].age);
    }
    qsort(lst, n, sizeof(Stu), cmpa);
    prt(lst, n);
    printf("\n");
    qsort(lst, n, sizeof(Stu), cmpb);
    prt(lst, n);
    return 0;
}
