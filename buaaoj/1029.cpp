#include <iostream>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    string str;
    cin >> str;
    int l = str.length();
    if(l % 2){
        cout << "NO" << endl;
        return 0;
    }else{
        l /= 2;
    }
    for(int i = 0; i < l; i++){
        bool flag = 1;
        for(int j = i; j-i < l && flag; j++){
            if(j >= l){
                if(str[j-l] != str[j]){
                    flag = 0;
                }
            }else{
                if(str[j] != str[j+l]){
                    flag = 0;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
