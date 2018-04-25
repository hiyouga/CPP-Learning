#include <cstdio>
#include <cstring>

unsigned int a[2000005];

int main()
{
	int n, m, t;
	while(scanf("%d %d", &n, &m) == 2){
		int p = 1;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++){
			scanf("%d", &t);
			if(!a[t]){
				a[t] = p;
				p++;
			}
		}
		for(int i = 1; i <= m; i++){
			scanf("%d", &t);
			if(a[t])
				printf("%d\n", a[t]);
			else
				printf("error\n");
		}
	}
	return 0;
}