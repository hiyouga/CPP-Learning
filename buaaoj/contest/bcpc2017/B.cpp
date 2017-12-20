#include <cstdio>
#include <cstring>

short mark[17000000];
char str[4500005];

int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--){
        scanf("%s",str);
        int f = strlen(str);
        int p = 1;
        bool loop = true;
        memset(mark, 0, sizeof(mark)); /// Hash table
        while(loop){
            int cnt = 0; /// Count of substrings
            int q = 1 << p;
            loop = false;
            int hsa = 0;
            for(int i = 0; i <= f - p; i++){ /// Foreach substrings
                if(i == 0){
                    for(int j = 0; j < p; j++){ /// Imitate 10 to 2
                        hsa <<= 1;
                        hsa += (str[i + j] - '0');
                    }
                }else{
                    hsa &= ((1<<(p-1)) - 1);
                    hsa <<= 1;
                    hsa += (str[i + p - 1] - '0');
                }
                if(mark[hsa] != p){ /// Unstaticed
                    cnt++;
                    mark[hsa] = p;
                }
                if(cnt == q){
                    if(p != 23) loop = true;
                    break;
                }
            }
            p++;
        }
        printf("%d\n", p-1);
    }
    return 0;
}
