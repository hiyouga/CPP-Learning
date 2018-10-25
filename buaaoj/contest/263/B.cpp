#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	long long a, b;
	while (n--) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", (a - 1) * (b - 1) - 1);
	}
	return 0;
}