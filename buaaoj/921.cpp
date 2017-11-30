#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lld unsigned long long

using namespace std;


lld gcd(lld m, lld n)
{
	if(m<n) return gcd(n, m);
	if(n == 0) return m;
	return gcd(n, m%n);
}

int main()
{
	int n;
	cin >> n;
	lld a[n], p, q, t, m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0) t = a[i];
		t = gcd(t, a[i]);
	}
	int f = 1;
	m = 1;
	while(f){
		m++;
		f = 0;
		for(int i = 0; i < n; i++){
			if(a[i]%m != 0) f = 1;
		}
	}
	cout << t/m << endl;
}