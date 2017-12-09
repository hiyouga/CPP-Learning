#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int gcd(int p, int q)
{
	if(p < q) return gcd(q, p);
	if(q == 0) return p;
	return gcd(q, p%q);
}

int main()
{
	NOTLE

	int n, k;
	cin >> n;
	int a[n+1], b[n+1];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	a[n] = 1, b[n] = 0;
	for(int i = n-1; i >= 0; i--){
		a[i] = a[i] * a[i+1] + b[i+1];
		b[i] *= a[i+1];
		k = gcd(a[i], b[i]);
		a[i] /= k;
		b[i] /= k;
	}
	cout << b[0] << " " << a[0] << endl;
}