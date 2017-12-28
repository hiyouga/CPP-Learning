#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int n, a, b;
    cin >> n >> a >> b;
    if(a < b) swap(a, b);
    int d, da = 1;
    int sum = a+b;
    int na = n * a / sum;
    int nb = n - na;
    cout << min(a/na, b/nb) << endl;
    return 0;
}
