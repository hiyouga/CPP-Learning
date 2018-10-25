#include <cstdio>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int s = 1;
		while (n >> s) {
			s++;
		}
		printf("%d\n", s);
	}
	return 0;
}