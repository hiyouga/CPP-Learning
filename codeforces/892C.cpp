#include <iostream>
#include <cstdlib>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

long long gcd(long long x, long long y)
{
    if(x > y) return gcd(y,x);
    if(x == 0) return y;
    return gcd(y%x,x);
}

int main()
{
    NOTLE

    int n, t, flag = 1;
    cin >> n;

    long long a[n], b[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    if(n==1 && a[0]==1){
        cout << 0 << endl;
        exit(0);
    }

    for(t = n; t > 1 && flag; t--){
        for(int k = 0; k < t-1 && flag; k++){
            a[k] = gcd(a[k], a[k+1]);
            if(a[k] == 1) flag = 0;
        }
    }
    if(t == 1 && a[0] != 1){
        cout << -1 << endl;
    }else{
        int p = 0;
        for(int i = 0; i < n; i++){
            if(b[i] != 1) p++;
        }
        cout << n-t+p-1;
    }
}
