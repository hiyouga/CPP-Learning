#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXN 999

int main()
{
    int i, j, r, u, k, n, dp, flag, m;
    FILE * in, * out;
    char str[MAXN], nst[MAXN], list[50][MAXN];
    in = fopen("listin.txt", "r");
    out = fopen("listout.txt", "w");
    scanf("%d", &n);
    getchar();
    while(fgets(str, MAXN, in)){
        k = 0, flag = 0, m = 0, dp = 0;
        for(r = 0; (str[r] != '\0') && (str[r] != '\n'); r++){///将句子拆分为单词
            if(!isspace(str[r]) && str[r] != ':'){
                list[k][m++] = str[r];
                flag = 1;
            }else{
                if(flag){
                    list[k++][m] = '\0';
                    m = 0;
                    flag = 0;
                }
            }
            if(str[r] == ':')
                dp = k;///记录冒号位置
        }
        if(flag){///处理最后一个单词
            list[k++][m] = '\0';
        }
        ///合并到新字符串
        nst[n-1] = ':';
        ///处理冒号前字符串
        i = 0;
        for(j = 0; j < dp; j++){
            for(u = 0; list[j][u] != '\0'; u++){
                nst[i++] = list[j][u];
            }
            nst[i++] = ' ';
        }
        while(i < n-1){
            nst[i] = ' ';
            i++;
        }
        i = n;
        ///处理冒号后字符串
        for(j = dp; j < k; j++){
            nst[i++] = ' ';
            for(u = 0; list[j][u] != '\0'; u++){
                nst[i++] = list[j][u];
            }
        }
        nst[i] = '\0';
        //puts(nst);
        fputs(nst, out);
        fputc('\n', out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
