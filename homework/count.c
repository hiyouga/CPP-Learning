#include <stdio.h>
#include <string.h>

int main()
{
    int i, t, n, cnt[10], maxp = 0;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &t);
        if(t < 0) t = -1 * t;
        if(t == 0) cnt[0]++;
        while(t > 0){
            cnt[t%10]++;
            t /= 10;
        }
    }
    for(i = 0; i < 10; i++){
        if(cnt[i] > cnt[maxp]){
            maxp = i;
        }
    }
    printf("%d", maxp);
    return 0;
}
