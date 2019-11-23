#include <iostream>
#include <cmath>
#include <algorithm>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

long long ans[100005];

int main()
{
    NOTLE
    int t = 0;
    long long n;
    cin >> n;
    long long ite = sqrt(n+1);
    long long tot = (n*(n+1))>>1;
    for (long long i = 1; i <= ite; i++) {
        long long ni = n / i;
        if (i * ni == n) {
            ans[t++] = (tot - ni*(ni-1)/2*i)/ni;
            ans[t++] = (tot - i*(i-1)/2*ni)/i;
        }
    }
    sort(ans, ans+t);
    t = unique(ans, ans+t) - ans;
    for (int i = 0; i < t; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
