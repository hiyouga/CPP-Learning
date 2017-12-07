#include <iostream>

using namespace std;

void rec_act_set (int * s, int * f, int k, int n)
{
	int m = k + 1;
	while (m <= n && s[m] < f[k]) {
		m++;
	}
	if (m <= n) {
		cout << m << endl;
		rec_act_set(s, f, m, n);
	}
}

void greedy_act_set (int * s, int * f, int n)
{
	int k = 1;
	cout << k << endl;
	for (int m = 2; m <= n; m++) {
		if (s[m] >= f[k]) {
			cout << m << endl;
			k = m;
		}
	}
}

int main()
{
	int s[12] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int f[12] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
	rec_act_set(s, f, 0, 11);
	greedy_act_set(s, f, 11);
	return 0;
}