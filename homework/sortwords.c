#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXN 99

void swap(int * m, int * n)///交换函数
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
    ///打开文件
    if(argc != 3) return -1;///命令行参数错误
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    ///处理文件内容
    while((c = fgetc(in)) != EOF){
        if(isalpha(c)){///添加单词
            list[k][m++] = c;
            flag = 1;
        }else{
            if(flag){
                hash[t++] = k;///散列寻址表
                list[k++][m] = '\0';///k增加1
                m = 0;
                flag = 0;
            }
        }
    }
    if(flag){///处理最后一个单词
        hash[t++] = k;
        list[k++][m] = '\0';
    }
    ///选择排序(伪
    for(i = 0; i < k; i++){
        max_p = i;
        for(j = i+1; j < k; j++){
            ans = strcmp(list[hash[max_p]], list[hash[j]]);///比较字符串
            if(ans > 0){
                max_p = j;
            }else if(ans == 0){
                hash[j] = -1;///清除元素
            }
        }
        if(max_p != i)///寻址表元素交换
            swap(&hash[i], &hash[max_p]);
    }
    ///输出到文件
    for(i = 0; i < k; i++){
        if(hash[i] != -1){///跳过重复单词
            fputs(list[hash[i]], out);
            fputc(' ', out);
        }
    }
    return 0;
}
