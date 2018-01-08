#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    unsigned long long i = 0, k, n, b = 1;
    cin >> n >> k;
    if(k == 1){
        cout << n << endl;
    }else{
        while(n > 0){
            n >>= 1;
            i++;
        }
        cout << (b<<i)-1 << endl;
    }
    return 0;
}
