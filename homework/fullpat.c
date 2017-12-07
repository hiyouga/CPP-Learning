///~8s
#include <stdio.h>
#include <string.h>

int n, used[10], num[10];
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void dfs(int x)
{
    int i;
    if(x >= n){
        for(i = 0; i < n; i++){
            if(i != 0) printf(" ");
            printf("%d", num[i]);
        }
        printf("\n");
        return;
    }
    for(i = 0; i < n; i++){
        if(!used[i]){
            num[x] = a[i];
            used[i] = 1;
            dfs(x+1);
            used[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    memset(used, 0, sizeof(used));
    dfs(0);
    return 0;
}
