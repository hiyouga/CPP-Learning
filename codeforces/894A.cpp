#include <iostream>
#include <cstdlib>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int t = 0, k, n = 0;
    string raw;
    char str[100];
    cin >> raw;
    int l = raw.length();
    for(k = 0; k < l; k++){
        if(raw[k]=='Q' || raw[k]=='A') str[t++] = raw[k];
    }
    for(int i = 0; i <= k; i++){
        if(str[i] == 'Q'){
            for(int p = i+1; p <= k; p++){
                if(str[p] == 'A'){
                    for(int q = p+1; q <= k; q++){
                        if(str[q] == 'Q') n++;
                    }
                }
            }
        }
    }
    cout << n << endl;
}
