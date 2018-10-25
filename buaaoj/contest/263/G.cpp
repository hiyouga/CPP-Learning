#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == -2147483648 && b == -1) {
		printf("2147483648\n");
	} else if (b == 0) {
		printf("error\n");
	} else if(a % b == 0) {
		printf("%d\n", a / b);
	} else if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
		printf("%d\n", a / b - 1);
	} else {
		printf("%d\n", a / b);
	}
}