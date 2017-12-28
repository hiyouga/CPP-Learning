#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    const int INF = 0x3f3f3f3f;

    int t[3];
    cin >> t[0] >> t[1] >> t[2];
    sort(t, t+3);
    if(t[0] == 1){
        cout << "YES";
    }else if(t[0] == 2 && t[1] == 2){
        cout << "YES";
    }else if(t[0] == 3 && t[1] == 3 && t[2] == 3){
        cout << "YES";
    }else if(t[0] == 2 && t[1] == 4 && t[2] == 4){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
