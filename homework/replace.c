#include <stdio.h>
#include <ctype.h>
#define MAXN 9999
int main()
{
    ///初始化变量
    int i = 0, j, t, v, k = 0, m = 0, n = 0;
    char c, rep[MAXN], ple[MAXN], str[MAXN];
    FILE * in, * out;
    ///读入变量
    in = fopen("filein.txt", "r");
    out = fopen("fileout.txt", "w");
    while((c = getchar()) != '\n')///被替换字符串
        rep[m++] = tolower(c);///提前转换为小写
    while((c = getchar()) != '\n')///待替换字符串
        ple[n++] = c;
    while((c = fgetc(in)) != EOF)///文件内容
        str[k++] = c;
    ///文件处理
    while(i < k){
        j = 0, t = i;///t:备份i
        while(tolower(str[t++]) == rep[j++]){///进入比较处理
            if(rep[j] == '\0'){///匹配成功
                i += j;
                for(v = 0; ple[v] != '\0'; v++)///输出新字符串
                    fputc(ple[v], out);
                break;
            }
        }
        fputc(str[i], out);
        i++;
    }
    ///文件关闭
    fclose(in);
    fclose(out);
    return 0;
}
