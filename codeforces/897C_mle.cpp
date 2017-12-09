#include <iostream>
#include <cstring>

#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

string s[10005];

string kotori(int k)
{
    if(s[k][0] != '\0'){
        return s[k];
    }else{
        s[k] = "What are you doing while sending \""+kotori(k-1)+"\"? Are you busy? Will you send \""+kotori(k-1)+"\"?";
        return s[k];
    }
}

int main()
{
    NOTLE
    int q, n;
    unsigned long long k;
    cin >> q;
    s[0] = "What are you doing at the end of the world? Are you busy? Will you save us?";
    for(int i = 0; i < q; i++){
        cin >> n >> k;
        kotori(n);
        if(k <= s[n].length()){
            cout << s[n][k-1];
        }else{
            cout << '.';
        }
    }
    cout << endl;
}