#include <iostream>
#include <cstring>

#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

char kotori(unsigned long long k)
{

}

int main()
{
    NOTLE
    int q, n;
    unsigned long long k;
    s[0] = "What are you doing at the end of the world? Are you busy? Will you save us?";
    //cout << kotori(3);
    cin >> q;
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
