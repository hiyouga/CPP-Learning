#include <stdio.h>

int rev(char * a, int l, int f)
{
    int i, j, flag = 1, k = 0;
    char temp;
    if(l == 1) return 1;
    for(i = 0, j = l-1; i <= j; i++, j--){
        if(f){
        	if(a[i] == '0' && flag){
	            j++, k++;
	            continue;
	        }else{
	            flag = 0;
	        }
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
    int i, r = 1, flag = 1, t, d = 0, m = 0, n = 0, k = 0, z = 1;
    char c, a[100], b[100], s[200];
    while((c = getchar()) != '\n')
        a[m++] = c;
    while((c = getchar()) != '\n')
        b[n++] = c;
    a[m] = '\0', b[n] = '\0';
    //printf("%s\n%s\n", a, b);return 0;
    m = rev(a, m, 1);
    n = rev(b, n, 1);
    if(m+n == 0){
        printf("0\n");
        return 0;
    }
    if(m < n){
        printf("-");
        r = -1;
    }
    if(m == n){
        while(z <= m){
            if(a[m-z] < b[n-z]){
                printf("-");
                r = -1;
                break;
            }
            z++;
        }
    }
    while(m < n) a[m++] = '0';
    while(n < m) b[n++] = '0';
    //printf("*%d %d\n", m, n);
    while(k < n){//!k:pos of s
        if(r == -1){
            t = b[k] + d - a[k];
        }else{
            t = a[k] + d - b[k];
        }
        //printf("%d", t);
        if(t < 0){
            s[k++] = 10 + t + '0';
            d = -1;
        }else{
            s[k++] = t + '0';
            d = 0;
        }
    }
    k = rev(s, k, 0);
    for(i = 0; i < k; i++){
        if(s[i] == '0' && flag){
            continue;
        }else{
            flag = 0;
        }
        printf("%c", s[i]);
    }
    if(flag){
        printf("0\n");
    }
    return 0;
}
