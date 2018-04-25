#include <iostream>
#include <algorithm>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    int k = 0;
    if(l == 1 && r == n){
        cout << 0 << endl;
        return 0;
    }
    if(l == 1){
        cout << abs(r - pos) + 1 << endl;
        return 0;
    }
    if(r == n){
        cout << abs(pos - l) + 1 << endl;
        return 0;
    }
    cout << r - l + min(abs(pos-l), abs(pos-r)) + 2 << endl;
    return 0;
}
