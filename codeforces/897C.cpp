#include <iostream>
#include <cstring>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

string a = "What are you doing while sending \"", b = "\"? Are you busy? Will you send \"", c = "\"?", d = "What are you doing at the end of the world? Are you busy? Will you save us?";
int e = a.size(), f = b.size(), g = c.size(), h = d.size();
long long t[100001];

char kotori(int n, unsigned long long k)
{
    if(n == 0){
        if(k < h){
            return d[k];
        }else{
            return '.';
        }
    }
    if(k < e)
        return a[k];
    k -= e;
    if(k < t[n-1])
        return kotori(n-1, k);
    k -= t[n-1];
    if(k < f)
        return b[k];
    k -= f;
    if(k < t[n-1])
        return kotori(n-1, k);
    k -= t[n-1];
    if(k < g)
        return c[k];
    return '.';
}

int main()
{
    NOTLE
    int q, n;
    unsigned long long k;
    t[0] = h;
    for(int i = 1; i < 100000; i++){
        t[i] = e + f + g + t[i-1]*2;
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> n >> k;
        cout << kotori(n, k-1);
    }
    cout << endl;
    return 0;
}
