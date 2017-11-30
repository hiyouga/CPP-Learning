#include <iostream>
#include <cstring>
#define MAXSIZE 1000

using namespace std;

char b[MAXSIZE][MAXSIZE], c[MAXSIZE][MAXSIZE];

void lcs_length(string x, string y)
{
	int m = x.length(), n = y.length();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(x[i-1] == y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 2;//leftup
			} else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 3;//up
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = 1;//left
			}
		}
	}
}

void print_lcs(string x, int i, int j)
{
	if(i == 0 || j == 0) return;
	if (b[i][j] == 2) {
		print_lcs(x, i-1, j-1);
		cout << x[i-1];
	} else if (b[i][j] == 3) {
		print_lcs(x, i-1, j);
	} else {
		print_lcs(x, i, j-1);
	}
}

int main()
{
	string x = "abbcdhiyougayz", y = "akvhiyougzfj";
	int m = x.length(), n = y.length();
	memset(c, 0, sizeof(c));
	lcs_length(x, y);
	print_lcs(x, m, n);
	return 0;
}