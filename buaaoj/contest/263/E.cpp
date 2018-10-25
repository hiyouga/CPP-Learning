#include <cstdio>

int main()
{
	int a;
	scanf("%d", &a);
	if (a >= 65 && a <= 90) {
		printf("uppercase\n");
	} else if (a >= 97 && a <= 122) {
		printf("lowercase\n");
	} else if (a >= 48 && a <= 57) {
		printf("digit\n");
	} else {
		printf("other character\n");
	}
}