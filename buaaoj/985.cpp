#include <iostream>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int a[130];
    memset(a, 0, sizeof(a));
    char c;
    while(cin >> c){
        a[c]++;
    }
    for(int i = 48; i < 58; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 97; i < 123; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 65; i < 91; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
