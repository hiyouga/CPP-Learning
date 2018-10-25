#include <cstdio>

int main()
{
	int n, a;
	scanf("%d", &n);
	long long A = 0, B = 0;
	while (n--) {
		scanf("%d", &a);
		A += a;
		B ^= a;
	}
	printf("%lld\n", A|B);
}