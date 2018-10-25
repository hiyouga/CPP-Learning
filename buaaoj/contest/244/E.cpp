#include <cstdio>

const int INF = 0x3f3f3f3f;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int profit = 0, low = INF, high = 0, temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (temp < low) {
				high = low = temp;
			}
			high = temp > high ? temp : high;
			profit = (high - low) > profit ? (high - low) : profit;
			//printf("*%d %d\n", low, high);
		}
		if (profit) {
			printf("%d\n", profit);
		} else {
			printf("No solution\n");
		}
	}
	return 0;
}