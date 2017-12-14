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

    for(i = 0; i <= n+1; i++){///给标记矩阵加边
        vis[0][i] = 1;
        vis[n+1][i] = 1;
        vis[i][0] = 1;
        vis[i][n+1] = 1;
    }

    i = 1, j = 1;///初始位置
    for(t = 1; t <= n*n; t++){
        if(vis[i][j]){///走到边界||已存在数字
            if(aj == 1){///右->下
                j--;
                ai++, aj--;
            }else if(ai == 1){///下->左
                i--;
                ai--, aj--;
            }else if(aj == -1){///左->上
                j++;
                ai--, aj++;
            }else if(ai == -1){///上->右
                i++;
                ai++, aj++;
            }
            t--;

        }
        vis[i][j] = 1;///记录已经过位置
        mat[i][j] = t;
        i += ai;
        j += aj;
    }
    ///输出到文件
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            fprintf(out, "%5d", mat[i][j]);
        }
        fprintf(out, "\n");
    }
    ///关闭文件
    fclose(out);
    return 0;
}
