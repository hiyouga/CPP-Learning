#include <stdio.h>
#include <ctype.h>
#define MAXN 99

int cmp(char * m, char * n)///比较函数，m<n返回1，m>n返回2，m=n返回3
{
    int i = 0, j = 0;
    while(m[i] != '\0' && n[j] != '\0'){
        if(m[i] > n[j])
            return 2;
        if(m[i] < n[j])
            return 1;
        i++, j++;
    }
    while(m[i] != '\0') i++;
    while(n[j] != '\0') j++;
    if(i < j)
        return 1;
    if(i > j)
        return 2;
    if(i == j)
        return 3;
    return 0;
}

void swap(int * m, int * n)
{
    int r = *m;
    *m = *n;
    *n = r;
}

int main(int argc, const char * argv[])
{
    int i, j, ans, t = 0, max_p, flag = 0, k = 0, m = 0, hash[MAXN];
    char c, list[MAXN][MAXN];
    FILE * in, * out;

    if(argc != 3) return -1;
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");

    while((c = fgetc(in)) != EOF){
        if(isalpha(c)){
            list[k][m++] = c;
            flag = 1;
        }else{
            if(flag){
                hash[t++] = k;///散列寻址表
                list[k++][m] = '\0';
                m = 0;
                flag = 0;
            }
        }
    }
    if(flag){///处理最后一个单词
        hash[t++] = k;
        list[k++][m] = '\0';
    }
    for(i = 0; i < k; i++){///选择排序(伪
        max_p = i;
        if(max_p == -1) continue;
        for(j = i+1; j < k; j++){
            ans = cmp(list[hash[max_p]], list[hash[j]]);
            if(ans == 2){
                max_p = j;
            }else if(ans == 3){
                hash[j] = -1;///清除元素
            }
        }
        if(max_p != i)
            swap(&hash[i], &hash[max_p]);
    }
    for(i = 0; i < k; i++){
        if(hash[i] != -1){
            puts(list[hash[i]]);
            fputs(list[hash[i]], out);
            fputc(' ', out);
        }
    }
    return 0;
}
