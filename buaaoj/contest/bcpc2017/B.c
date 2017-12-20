#include <stdio.h>
#include <string.h>
#include <math.h>

int mark[8400000];
char str[8400000];

int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--){
        int i, j, mid, hsa, cnt, l = 1, r = 23;
        gets(str);
        int f = strlen(str);
        int p = 1;
        memset(mark, 0, sizeof(mark)); /// Hash table
        while(l < r){
            mid = (l + r) / 2; /// Length of substrings
            cnt = 0; /// Count of substrings
            for(i = 0; i <= f - mid; i++){ /// Foreach substrings
                hsa = 0;
                for(j = 0; j < mid; j++){ /// Imitate 10 to 2
                    hsa = 2 * hsa + (str[i + j] - '0');
                }
                if(mark[hsa] != p){ /// Unstaticed
                    cnt++;
                    mark[hsa] = p;
                }
            }
            if(cnt == pow(2, mid)){
                if(mid == 22){
                    r = 23;
                    break;
                }
                l = mid + 1;
            }else{
                r = mid;
            }
            p++;
        }
        printf("%d\n", r);
    }
    return 0;
}
