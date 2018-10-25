#include <cstdio>

int main()
{
	int n;
	int ord[71];
	int temp = 0;
	char hex[3];
	while (temp < 10) {
		ord[48+temp] = temp;
		temp++;
	}
	while (temp < 16) {
		ord[55+temp] = temp;
		temp++;
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%s", hex);
		printf("%c", ord[hex[0]]*16+ord[hex[1]]);
	}
	printf("\n");
}