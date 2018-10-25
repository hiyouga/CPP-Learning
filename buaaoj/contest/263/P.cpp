#include <iostream>

using namespace std;

int d2b(int dec)
{
	int res = 0, j = 1;
	while (dec) {
		res += (dec & 1) * j;
		j *= 10;
		dec >>= 1;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= 513; i++) {
		if (d2b(i) > n) {
			cout << i-1 << endl;
			break;
		}
	}
}