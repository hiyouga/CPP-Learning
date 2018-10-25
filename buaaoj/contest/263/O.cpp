#include <iostream>

using namespace std;

const long long M = 0x8000000000000000;

int main()
{
	long long a, b;
	unsigned long long c, d;
	cin >> a >> b;
	if (a == M && b == M) {
		cout << "-18446744073709551616" << endl;
	} else if (a == 0 || b == 0) {
		cout << a + b << endl;
	} else if (a > 0 && b > 0) {
		c = a, d = b;
		cout << c + d << endl;
	} else if (a < 0 && b < 0) {
		c = -a, d = -b;
		cout << "-" << c + d << endl;
	} else {
		cout << a + b << endl;
	}
}