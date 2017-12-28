#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
const int mod = 1000000007;
const int MAXN = 1000000;
long long f[MAXN * 2 + 10];
int n,m;

long long pow_c(long long a, long long b, long long m) {
	long long ret = 1;
	while (b > 0) {
		if(b & 1)
			ret = (ret * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return ret;
}

int main(){
    cout << pow_c(5, mod-2, mod);
    return 0;
}
