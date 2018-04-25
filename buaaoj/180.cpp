#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int t, n;
	cin >> n;
	unsigned long long s = 0;
	for(int i = 0; i < n; i++){
		cin >> t;
		s += t;
	}
	for(int i = 0; i < n-1; i++){
		cin >> t;
		s -= t;
	}
	cout << s << endl;
	return 0;
}