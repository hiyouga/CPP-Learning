#include <iostream>
#include <vector>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int t = 0, n, s = 0;
    cin >> n;
    //n = 10000000;
    s = n-1;
    vector<int> prime(n+5);
    vector<bool> check(n+5, 0);
    for(int i = 2; i <= n; i++){
        if(!check[i]){//!is prime
            prime[t++] = i;
        }
        for(int j = 0; j < t; j++){
            if(i * prime[j] > n) break;
            check[i * prime[j]] = 1;
            s--;
            if(i % prime[j] == 0) break;
        }
    }
    cout << s << endl;
    return 0;
}
