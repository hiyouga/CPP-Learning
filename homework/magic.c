#include <stdio.h>
#include <string.h>
#define MAXN 25

int main()
{
    int n, t, i, j, ai = 0, aj = 1, mat[MAXN][MAXN], vis[MAXN][MAXN];
    FILE * out;
    out = fopen("file.out", "w");
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));

    for(i = 0; i <= n+1; i++){///����Ǿ���ӱ�
        vis[0][i] = 1;
        vis[n+1][i] = 1;
        vis[i][0] = 1;
        vis[i][n+1] = 1;
    }

    i = 1, j = 1;///��ʼλ��
    for(t = 1; t <= n*n; t++){
        if(vis[i][j]){///�ߵ��߽�||�Ѵ�������
            if(aj == 1){///��->��
                j--;
                ai++, aj--;
            }else if(ai == 1){///��->��
                i--;
                ai--, aj--;
            }else if(aj == -1){///��->��
                j++;
                ai--, aj++;
            }else if(ai == -1){///��->��
                i++;
                ai++, aj++;
            }
            t--;

        }
        vis[i][j] = 1;///��¼�Ѿ���λ��
        mat[i][j] = t;
        i += ai;
        j += aj;
    }
    ///������ļ�
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            fprintf(out, "%5d", mat[i][j]);
        }
        fprintf(out, "\n");
    }
    ///�ر��ļ�
    fclose(out);
    return 0;
}
