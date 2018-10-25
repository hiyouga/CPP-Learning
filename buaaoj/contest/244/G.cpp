#include <cstdio>
#include <unordered_set>
#include <set>

using namespace std;

//int a[20000007] = {0};

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		bool flag = true;
		int t, temp, b[n];
		unordered_set<int> Sa;
		set<int> Sf;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			Sa.insert(temp);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", b + i);
		}
		scanf("%d", &t);
		for (int i = 0; i < n; i++) {
			if (Sa.count(t - b[i])) {
				Sf.insert(t - b[i]);
			}
		}
		set<int>::iterator p;
		for (p = Sf.begin(); p != Sf.end(); p++) {
			flag = false;
			printf("%d %d\n", *p, t - *p);
		}
		if (flag) {
			printf("OTZ\n");
		}
		printf("\n");
	}
}