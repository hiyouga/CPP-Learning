#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXN 999

int main()
{
    int i, j, r, u, k, n, dp, flag, m;
    char str[MAXN], nst[MAXN], list[50][MAXN];
    scanf("%d", &n);
    getchar();
    while(gets(str)){
        k = 0, flag = 0, m = 0, dp = 0;
        for(r = 0; str[r] != '\0'; r++){
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
                dp = k;///ð��λ��
        }
        if(flag){///�������һ������
            list[k++][m] = '\0';
        }
        ///�ϲ������ַ���
        nst[n] = ':';
        ///����ð��ǰ�ַ���
        i = n - 1;
        for(j = dp - 1; j >= 0; j--){
            nst[i--] = ' ';
            for(u = strlen(list[j])-1; u >=0; u--){
                nst[i--] = list[j][u];
            }
        }
        while(i >= 0){
            nst[i] = ' ';
            i--;
        }
        i = n + 1;
        ///����ð�ź��ַ���
        for(j = dp; j < k; j++){
            nst[i++] = ' ';
            for(u = 0; u < strlen(list[j]); u++){
                nst[i++] = list[j][u];
            }
        }
        nst[i] = '\0';
        puts(nst);
    }
    return 0;
}
