#include <iostream>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 20
using namespace std;

int det(int a[][MAXN], int n)
{
	if(n == 1) return a[0][0];
	int s = 0, now = 1;
	int b[MAXN][MAXN];
	for(int k = 0; k < n; k++) {
		for(int i = 1; i < n; i++){
			int sit = 0;
			for(int j = 0; j < n; j++){
				if(j == k) continue;
				b[i-1][sit++] = a[i][j];
			}
		}
		s += now * a[0][k] * det(b, n-1);
		now *= -1;
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	int a[MAXN][MAXN];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	cout << det(a, n) << endl;
}