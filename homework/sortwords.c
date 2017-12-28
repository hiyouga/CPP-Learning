#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXN 99

void swap(int * m, int * n)///��������
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
    ///���ļ�
    if(argc != 3) return -1;///�����в�������
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    ///�����ļ�����
    while((c = fgetc(in)) != EOF){
        if(isalpha(c)){///��ӵ���
            list[k][m++] = c;
            flag = 1;
        }else{
            if(flag){
                hash[t++] = k;///ɢ��Ѱַ��
                list[k++][m] = '\0';///k����1
                m = 0;
                flag = 0;
            }
        }
    }
    if(flag){///�������һ������
        hash[t++] = k;
        list[k++][m] = '\0';
    }
    ///ѡ������(α
    for(i = 0; i < k; i++){
        max_p = i;
        for(j = i+1; j < k; j++){
            ans = strcmp(list[hash[max_p]], list[hash[j]]);///�Ƚ��ַ���
            if(ans > 0){
                max_p = j;
            }else if(ans == 0){
                hash[j] = -1;///���Ԫ��
            }
        }
        if(max_p != i)///Ѱַ��Ԫ�ؽ���
            swap(&hash[i], &hash[max_p]);
    }
    ///������ļ�
    for(i = 0; i < k; i++){
        if(hash[i] != -1){///�����ظ�����
            fputs(list[hash[i]], out);
            fputc(' ', out);
        }
    }
    return 0;
}
