#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, k, a[51];
    char c;
    memset(a, 0, sizeof(a));
    while(1){
        scanf("%d%d%c", &n, &k, &c);
        a[k] += n;
        if(c == '\n') break;
    }
    while(1){
        scanf("%d%d%c", &n, &k, &c);
        a[k] += n;
        if(c == '\n') break;
    }
    for(i = 50; i >= 0; i--){
        if(a[i] != 0){
            printf("%d %d ", a[i], i);
        }
    }
}
