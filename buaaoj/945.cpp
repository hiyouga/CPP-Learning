#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

long long gcd(long long x, long long y)
{
	if(x > y) return gcd(y, x);
	if(x == 0) return y;
	return gcd(y % x, x);
}

int main()
{
	long long a, b, p;
	cin >> a >> b >> p;
	long long d = gcd(a, b);
	a = a / d;
	b = b / d;
	long long x;
	for(x = 0; x < b; x++){
		if((b * x - 1) % p == 0)
			break;
	}
	cout << a * x % p << endl;
}