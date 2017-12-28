#include <cstdio>
#define MAXN 100005

int main()
{
	int t, n, q, k;
	unsigned int s, pre[MAXN], lst[MAXN], a[MAXN];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &q);
		for(int i = 0; i < n; i++)
			scanf("%d", a+i);
		pre[0] = 1;
		lst[n-1] = 1;
		for(int i = 1; i < n; i++){
			pre[i] = pre[i-1] * a[i-1];
			lst[n-i-1] = lst[n-i] * a[n-i];
		}
		while(q--){
			scanf("%d", &k);
			s = pre[k-1] * lst[k-1];
			printf("%u\n", s);
		}
	}
	return 0;
}