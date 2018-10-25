#include <iostream>

using namespace std;

int n, s = 0;

void step(int t)
{
	if (t >= n) {
		s += (t == n);
		return;
	}
	step(t+1);
	step(t+2);
}

int main()
{
	cin >> n;
	step(0);
	cout << s << endl;
	return 0;
}