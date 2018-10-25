#include <cstdio>

int prime[3001200];
bool check[50000001];

int main()
{
    int x, n = 50000001, t = 0;
    for(int i = 2; i <= n; i++){
        if(!check[i]){
            prime[t++] = i;
        }
        for(int j = 0; j < t; j++){
            if(i * prime[j] > n) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    while(scanf("%d", &x) != EOF){
        int j = 0;
        while(prime[j] <= x && j < 3001134) j++;
        printf("%d\n", j);
    }
    return 0;
}