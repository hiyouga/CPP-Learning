#include <cstdio>

int a[4000005];

int main()
{
	int n, m, t = 1;
	while (scanf("%d %d\n", &n, &m) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf("%d", a + i);
		}
		printf("Case %d:\n", t);
		while (n--) {
			int h, l = 0, r = m - 1;
			scanf("%d", &h);
			bool flag = false;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (a[mid] == h) {
					flag = true;
					break;
				} else if (a[mid] < h) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			if (flag) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
		t++;
	}
}