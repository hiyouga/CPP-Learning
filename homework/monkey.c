#include <stdio.h>
#include <string.h>
#define MAXN 999

int main()
{
    int n, d = 0, t, h, p, vis[MAXN];
    memset(vis, 0, sizeof(vis));
    scanf("%d %d %d", &n, &h, &p);///���� ���� ��ʼ
    p--;///0~n-1��ţ��ʼ�һ
    t = n;///�����
    while(t > 0){
        if(!vis[p]){
            d++;///����
            if(d == h){
                if(t == 1) printf("%d\n", p+1);
                vis[p] = 1;///����
                t--;///�������һ
                d = 0;///��������
            }
        }
        p = (p + 1) % n;
    }
    return 0;
}
