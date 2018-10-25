#include <cstdio>

int main()
{
	int n, temp;
	while (scanf("%d", &n) != EOF) {
		int x = 0;
		for (int i = 0; i < 2*n-1; i++) {
			scanf("%d", &temp);
			x ^= temp;
		}
		printf("%d\n", x);
	}
}