#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n;
    s = 0;
    long long d, k = n+1, l[n+5];

    for(int i = 1; i <= n; i++){
        cin >> l[i];
    }
    for(int i = n; i > 0; i--){
        d = i - l[i];//能杀到的人
        //cout << d << ends << k << ends << s << endl;
        if(d<0) d=0;
        if(i<k) s++;
        if(d < k){
            k = d;
        }
    }
    cout << s << endl;
}
