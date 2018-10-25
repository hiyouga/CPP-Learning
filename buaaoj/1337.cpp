#include <iostream>

using namespace std;

char mat[999][999];

int check(int i, int j, int k)
{
	for (int p = 0; p < k; p++) {
		for (int q = 0; q <= p; q++) {
			if (mat[i - p][j - q] != '-') {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int n, s = 0;
	cin >> n;
	cin.clear();
	cin.sync();
	for (int i = 0; i < n+2; i++) {
		mat[i][0] = mat[i][n+1] = mat[0][i] = mat[n+1][i] = '*';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mat[i][j] = cin.get();
		}
		cin.get();
	}
	/*for (int i = 0; i < n+2; i++) {
		for (int j = 0; j < n+2; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n+2; i++) {
		for (int j = 0; j < n+2; j++) {
			cout << i << j << ' ';
		}
		cout << endl;
	}*/
	for (int i = n; i > 0; i--) {
		for (int j = n; j >= i; j--) {
			for (int k = 1; k <= i; k++) {
				if (check(i, j, k)) {
					s = max(s, k);
				}
			}
		}
	}
	cout << s << endl;
}