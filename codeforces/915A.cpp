#include <iostream>
#include <algorithm>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = n-1; i >= 0; i--){
        if(k % a[i] == 0){
            cout << k / a[i] << endl;
            return 0;
        }
    }
}
