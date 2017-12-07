#include <stdio.h>

void sort(int * a, int l)///实现选择排序
{
    int max_p, i, j, temp;
    for(i = 0; i < l; i++){
        max_p = i;
        for(j = i+1; j < l; j++){
            if(a[j] > a[max_p]) max_p = j;
        }
        temp = a[i];
        a[i] = a[max_p];
        a[max_p] = temp;
    }
}

int main()
{
    ///初始化变量
    int t, m = 0, n = 0, i = 0, p = 0, q = 0, k, a[25], b[25], s[45];
    char c;
    ///输入数字
    do{
        scanf("%d%c", &t, &c);
        a[m++] = t;
    }while(c != '\n');
    sort(a, m);///输入后立即排序
    do{
        scanf("%d%c", &t, &c);
        b[n++] = t;
    }while(c != '\n');
    sort(b, n);
    ///合并新的数组
    while(p < m && q < n){
        if(a[p] == b[q]){
            p++, q++;
        }else if(a[p] > b[q]){
            s[i++] = a[p++];
        }else{
            s[i++] = b[q++];
        }
    }
    ///将剩余数字放入
    while(p < m) s[i++] = a[p++];
    while(q < n) s[i++] = b[q++];
    for(k = 0; k < i; k++){
        if(k != 0) printf(" ");
        printf("%d", s[k]);
    }

    return 0;
}
