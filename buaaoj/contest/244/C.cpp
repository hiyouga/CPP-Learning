#include <cstdio>

int mid;

void swap(int & a, int & b)
{
	int * c = new int;
	*c = a;
	a = b;
	b = *c;
	delete c;
}

int Partition(int * a, int lt, int rt)
{
	int pk = a[lt], p = lt;
	while (lt < rt) {
		while (a[rt] >= pk && lt < rt)
			rt--;
		a[lt] = a[rt];
		while (pk >= a[lt] && lt < rt)
			lt++;
		a[rt] = a[lt];
	}
	a[lt] = pk;
	return lt;
}

void QuickSort(int * a, int lt, int rt)
{
	if (lt < rt) {
		int k = Partition(a, lt, rt);
		if (k == mid) {
			return;
		} else if (k < mid) {
			QuickSort(a, k + 1, rt);
		} else {
			QuickSort(a, lt, k - 1);
		}
	}
}

int main()
{
	int n;
	while (scanf("%d\n", &n) != EOF) {
		mid = (n - 1) / 2;
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		QuickSort(a, 0, n - 1);
		printf("%d\n", a[mid]);
	}
}