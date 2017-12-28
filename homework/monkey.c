#include <stdio.h>
#include <string.h>
#define MAXN 999

int main()
{
    int n, d = 0, t, h, p, vis[MAXN];
    memset(vis, 0, sizeof(vis));
    scanf("%d %d %d", &n, &h, &p);///数量 步长 初始
    p--;///0~n-1编号，故减一
    t = n;///存活数
    while(t > 0){
        if(!vis[p]){
            d++;///报数
            if(d == h){
                if(t == 1) printf("%d\n", p+1);
                vis[p] = 1;///死ね
                t--;///存活数减一
                d = 0;///报数归零
            }
        }
        p = (p + 1) % n;
    }
    return 0;
}
