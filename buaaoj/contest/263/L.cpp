#include <cstdio>
#include <cstring>

int h[10000005];

int dup(int n)
{
	for (int i = 1; i <= n+1; i++) {
		scanf("%d", h+i);
	}
	for (int i = 1; i <= n+1; i++) {
		while (h[i] != i) {
			if (h[i] == h[h[i]]) {
				return h[i];
			}
			int temp = h[i];
			h[i] = h[temp];
			h[temp] = temp;
		}
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", dup(n));
	}
}