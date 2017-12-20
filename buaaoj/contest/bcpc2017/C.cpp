#include <iostream>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const long long NI = 500000004, SAN = 333333336, MOD = 1000000007;

int main()
{
    //NOTLE
    int p, m, n;
    cin >> p;
    while(p--){
        cin >> m >> n;
        long long s = (m-n);
        s = s * (m-n+1) % MOD;
        s = s * (m+5*n+2) % MOD;
        if(m <= 2*n){
            s = s*NI%MOD;
            s = s*SAN%MOD;
            cout << s << endl;
        }else{
            s = s * 4 % MOD;
            long long t = m - 2*n - 1;
            long long r = 0;
            if(t % 2 == 0){
                r = t * (t+2) % MOD;
                r = r * (2*t+5) % MOD;
                s = (s + r) % MOD;
            }else{
                r = (t+1) * (t+3) % MOD;
                r = r * (2*t+1) % MOD;
                s = (s + r) % MOD;
            }
            s = s*NI%MOD;
            s = s*NI%MOD;
            s = s*NI%MOD;
            s = s*SAN%MOD;
            cout << s << endl;
        }
    }
    return 0;
}
