#include <stdio.h>

int rev(char * a, int l)
{
    int i, j, flag = 1, k = 0;
    char temp;
    for(i = 0, j = l-1; i <= j; i++, j--){
        if(a[i] == '0' && flag){
            j++;
            k++;
            continue;
        }else{
            flag = 0;
        }
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        //printf("%c %c %d %d\n",a[i],a[j],i,j);
    }
    for(i = 0; i < l-k; i++)
        a[i] = a[i+k];
    return l-k;
}

int main()
{
    int i, r, flag = 1, t, d = 0, m = 0, n = 0, k = 0;
    char c, a[85], b[85], s[165];
    while((c = getchar()) != '\n')
        a[m++] = c;
    while((c = getchar()) != '\n')
        b[n++] = c;
    m = rev(a, m);
    n = rev(b, n);
    if(m+n == 0){
        printf("0");
        return 0;
    }
    if(m < n || (m == n && a[m-1] < b[n-1])){
        printf("-");
        r = -1;
    }
    while(m < n) a[m++] = '0';
    while(n < m) b[n++] = '0';
    while(k < n){//!k:pos of s
        t = a[k]*r + d - b[k]*r;
        if(t < 0){
            s[k++] = 10 - t * -1 + '0';
            d = -1;
        }else{
            s[k++] = t + '0';
            d = 0;
        }
    }
    rev(s, k);
    for(i = 0; i < k; i++){
        if(s[i] == '0' && flag){
            continue;
        }else{
            flag = 0;
        }
        printf("%c", s[i]);
    }
    return 0;
}
