#include <iostream>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    long long n, m;
    cin >> n >> m;
    if(n < 27){
        while((m - (1<<n)) >= 0){
            m -= (1<<n);
        }
    }
    cout << m << endl;
}
