#include <iostream>

using namespace std;

const long MOD = 1e9+7;

int main()
{
	long long pat[10005];
	pat[1] = 1;
	for(int i = 2; i <= 10001; i++){
		pat[i] = pat[i-1] * i % MOD;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long s = 0;
		for(int i = 1; i <= n; i++){
			s = (s + pat[i]) % MOD;
		}
		cout << s << endl;
	}
}