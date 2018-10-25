#include <cstdio>
#define MOD 10007

int pre[1000005];

int main()
{
	int temp, l, r, N, Q;
	while (scanf("%d %d", &N, &Q) != EOF) {
		pre[0] = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &temp);
			pre[i] = (pre[i-1] + (temp%MOD)) % MOD;
		}
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &l, &r);
			printf("%d\n", (pre[r] - pre[l-1] + MOD) % MOD);
		}
	}
}