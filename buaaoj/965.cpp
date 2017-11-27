#include <iostream>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int ml(int n, int q)
{
    if(q == 0) return 1;
    return n * ml(n-1, q-1);
}

int main()
{
    NOTLE
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    if(n < q){
        cout << 0 << endl;
    }else{
        cout << m * ml(n, q) * pow(p, n-q) << endl;
    }
}
