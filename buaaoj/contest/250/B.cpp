#include <cstdio>
#include <algorithm>

using namespace std;

int cal(int * a, int * b, int n, int mid) //返回小于等于mid的两数和的个数
{
	int cnt = 0; int j = n - 1;
	for (int i = 0; i < n; ++i) {
		while (j >= 0 && a[i] + b[j] > mid)
			--j;
		cnt += 1 + j;
	}
	return cnt;
}

int findK(int * a, int * b, int n, int k)
{
	sort(a, a + n);
	sort(b, b + n);
	int l = a[0] + b[0], r = a[n - 1] + b[n - 1];
	while (l <= r) {
		int mid = l + r >> 1;
		if (k <= cal(a, b, n, mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main()
{
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		int a[n], b[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		for (int i = 0; i < n; ++i)
			scanf("%d", b + i);
		printf("%d\n", findK(a, b, n, k));
	}
	return 0;
}