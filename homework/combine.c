#include <stdio.h>

int main()
{
    int m = 0, n = 0, p = 0, q = 0;
    char a[105], b[105], c;
    while((c = getchar()) != '\n')
        a[m++] = c;
    while((c = getchar()) != '\n')
        b[n++] = c;
    while(p < m && q < n){
        if(a[p] < b[q]){
            printf("%c", a[p++]);
        }else{
            printf("%c", b[q++]);
        }
    }
    while(p < m) printf("%c", a[p++]);
    while(q < n) printf("%c", b[q++]);
    return 0;
}
