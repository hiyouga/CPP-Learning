#include <iostream>
#include <algorithm>
#include <vector>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 998244353

using namespace std;

int main()
{
    NOTLE
    int n;
    cin >> n;
    long long fac[n+1], fact[n+1];
    fac[0] = fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i-1] * i % MOD;
        fact[i] = fact[i-1] * (n-i+1) % MOD;
    }
    long long res = 1;
    for (int i = 0; i < n; i++)
        res = (res + fact[i] * (fac[n-i]-1) % MOD + MOD) % MOD;
    cout << res << endl;
    return 0;
}
