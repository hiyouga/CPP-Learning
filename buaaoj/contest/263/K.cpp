#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	int n, m, temp;
	stack<int> a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		a.push(temp);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		b.push(temp);
	}
	int x = a.top();a.pop();
	int y = b.top();b.pop();
	int s = 1;
	while (!a.empty() && !b.empty()) {
		if (x == y) {
			x = a.top();a.pop();
			y = b.top();b.pop();
			s += 1;
		} else if (x > y) {
			y += b.top();b.pop();
		} else {
			x += a.top();a.pop();
		}
	}
	printf("%d\n", s);
}