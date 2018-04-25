#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    const unsigned long long INF = 0xffffffffffffffff;
    int n, l;
    unsigned long long s, t;
    cin >> n >> l;
    unsigned long long c[40] = {0};
    for(int i = 0; i < n; i++){
        cin >> c[i];
        c[i] = min(c[i], c[i-1] * 2);
    }
    t = c[n-1] * (l >> (n-1));
    s = c[n-1] + t;
    for(int i = n - 2; i >= 0; i--){
        if(1&(l >> (i-1))){
            t += c[i];
        }
        s = min(s, t+c[i]);
    }
    s = min(s, t);
    cout << s << endl;

}
