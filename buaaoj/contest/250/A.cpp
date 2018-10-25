#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 710

using namespace std;

struct node
{
	int s, k;
	node (int s, int k):s(s),k(k){}
	bool operator < (const node& a) const {
		return s > a.s;
	}
};


void merge(int * a, int * b, int * c, int n)
{
	priority_queue<node> q;
	for (int i = 0; i < n; i++) {
		q.push(node(a[i] + b[0], 0));
	}
	for (int i = 0; i < n; i++) {
		node t = q.top();
		q.pop();
		c[i] = t.s;
		int k =  t.k;
		if (k+1 < n) q.push(node(t.s - b[k] + b[k+1], k+1));
	}
}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		int v[n], p[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", p + i);
		}
		sort(p, p+n);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", v + j);
			}
			sort(v, v+n);
			if (i) merge(p, v, p, n);
		}
		for (int i = 0; i < n; i++) {
			if (i) printf(" ");
			printf("%d", p[i]);
		}
		printf("\n");
	}
}