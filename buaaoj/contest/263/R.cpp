#include <cstdio>
#include <algorithm>
//m*n*(m+1)*(n+1)/4

using namespace std;

int N = 0;
struct calc
{
	int ans, val;
} num[19800];

bool cmp(calc a, calc b)
{
	return a.val < b.val;
}

int solve(int g)
{
	int mid, lt = 0, rt = N-1;
	if (g >= num[rt].val) {
		return num[rt].ans;
	}
	if (g <= num[lt].val) {
		return num[lt].ans;
	}
	while (lt < rt) {
		if (rt - lt == 1) {
			mid = (g - num[lt].val) < (num[rt].val - g) ? lt : rt;
			break;
		}
		mid = (lt + rt) >> 1;
		if (num[mid].val == g) {
			break;
		} else if (num[mid].val > g) {
			rt = mid;
		} else {
			lt = mid;
		}
	}
	return num[mid].ans;
}

int main()
{
	int T, g, s;

	for (int m = 1; m <= 2000; m++) {
		for (int n = 1; n <= 2000; n++) {
			s = m * n * (m+1) * (n+1) / 4;
			if (s > 2000000) {
				break;
			}
			num[N].ans = m * n;
			num[N].val = s;
			N++;
		}
	}

	sort(num, num+N, cmp);

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &g);
		printf("%d\n", solve(g));
	}
}