#include <iostream>

using namespace std;

int n, s = 0;

void dest(int t, int d)
{
	if (d <= 0) {
		s += (d == 0);
		return;
	}
	for (int i = 1; i <= t; i++) {
		dest(i, d-i);
	}
}

int main()
{
	cin >> n;
	dest(n, n);
	cout << s << endl;
	return 0;
}
