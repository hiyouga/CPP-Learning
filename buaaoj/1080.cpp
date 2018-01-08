#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		long d = 0;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		int p = (n + 1) / 2 - 1;
		for(int i = 0; i < n; i++){
			d += abs(a[i] - a[p]);
		}
		cout << d << endl;
	}
}