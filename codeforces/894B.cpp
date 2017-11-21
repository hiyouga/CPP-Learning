#include <iostream>
#include <cstdlib>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    unsigned long long n, m, k, s = 1, MOD = 1e9+7;
    cin >> n >> m >> k;
    if(k == -1 && (n%2 != m%2)){
        cout << 0 << endl;
        return 0;
    }
    n--, m--;
    n %= MOD - 1;
    m %= MOD - 1;
    long long b = 2, p = n * m;
    while(p){
        if(p & 1) s = s * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    cout << s << endl;
}
