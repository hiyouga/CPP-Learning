#include <iostream>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int i = 0;
    string s[999];
    while(cin >> s[i++]) ;
    for(int j = i-2; j >=0; j--)
        cout << s[j] << " ";
    cout << endl;
}
