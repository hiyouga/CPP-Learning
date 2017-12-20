#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int t, d;
    cin >> t;
    while(t--){
        cin >> d;
        if(d % 72)
            cout << 32 << endl;
        else
            cout << 7 << endl;
    }
}
