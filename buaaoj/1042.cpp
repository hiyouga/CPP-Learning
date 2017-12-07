#include <iostream>
#include <algorithm>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int t = 0, a[9999];

void kakutani(int n, int k)
{
	if(k > 0) {
		a[t++] = n;
		kakutani(n * 2, k - 1);
		kakutani(n * 3 + 1, k - 1);
	}
}

int main()
{
	NOTLE
	int n, k;
	cin >> n >> k;
	kakutani(n * 2, k);
	kakutani(n * 3 + 1, k);
	sort(a, a+t);
	int l = unique(a, a+t) - a;
	for(int i = 0; i < l; i++){
		if(i != 0) cout << " ";
		cout << a[i];
	}
	return 0;
}