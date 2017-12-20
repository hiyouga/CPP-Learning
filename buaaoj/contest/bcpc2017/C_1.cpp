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
void init()
{
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= 2000000; i++)
        f[i] = (f[i - 1] * i) % mod;
}

long long pow_c(long long n,long long m)
{
    long long ans = 1;
    while(m > 0){
        if(m & 1)
            ans = (ans * n) % mod;
        m = m >> 1;
        n = (n * n) % mod;
    }
    return ans;
}

long long quick_pow(long long a, long long b, long long m) {
	long long ret = 1;
	while(b) {
		if(b&1) {
			ret = (ret*a)%m;
		}
		a = (a*a)%m;
		b >>= 1;
	}
	return ret;
}

long long computer()
{
    long long ans = f[n - 1 + m - 1];
    ans = (ans * pow_c( f[n-1], mod - 2)) % mod;
    ans = (ans * pow_c( f[m - 1] ,mod - 2)) % mod;
    return ans;
}
int main(){
    init();
    while(~scanf("%d%d",&n,&m)){
            cout<<computer()<<endl;
    }
    return 0;
}
