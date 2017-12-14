#include <iostream>
#include <algorithm>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int n, m = 0, d = 360;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(int i = n-1; i >= 0; i--){
        m += a[i];
        if(m >= 180){
            d = min(d, abs(180 - m));
            m -= a[i];
        }
    }
    d = min(d, abs(180 - m));
    cout << d * 2 << endl;
    return 0;
}
