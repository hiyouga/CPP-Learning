#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    unsigned long long k, s = 0, t[2] = {0, 0};
    for(int i = 0; i < n; i++){
        cin >> k;
        s += k;
    }
    for(int i = 0; i < n; i++){
        cin >> k;
        if(k > t[0]){
            t[1] = t[0];
            t[0] = k;
            continue;
        }
        if(k > t[1]){
            t[1] = k;
            continue;
        }
    }
    if(t[0]+t[1] >= s){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
