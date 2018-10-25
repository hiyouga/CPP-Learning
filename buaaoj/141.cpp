#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m, l, p, q;
		cin >> n >> m >> l;
		int a[n];
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		vector<set<int>> bridge(l);
		for (int i = 0; i < m; i++) {
			cin >> p >> q;
			bridge[q].insert(p);
		}
		for (int i = l - 1; i >= 0; i--) {
			set<int>::iterator ite;
			for (ite = bridge[i].begin(); ite != bridge[i].end(); ite++) {
				swap(a[*ite], a[*ite + 1]);
			}
		}
		cout << "Case " << t << " #:";
		for (int i = 0; i < n; i++) {
			cout << " " << a[i];
		}
		cout << endl;
	}
}