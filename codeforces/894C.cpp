#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int m, flag = 1;
    cin >> m;

    long long s[m];

    for(int i = 0; i < m; i++){
        cin >> s[i];
    }

    for(int p = 0; p < m && flag; p++)
        if(s[p] % s[0] != 0)
            flag = 0;

    if(!flag){
        cout << -1 << endl;
    }else{
        cout << m*2-1 << endl;
        for(int i = 0; i < m; i++){
            if(i!=0) cout << " " << s[0] << " ";
            cout << s[i];
        }
        cout << endl;
    }
}
