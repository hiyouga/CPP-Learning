#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void fd(int * a, int l, int r, int f)
{
    int m = (l+r)/2;
    if(l > r){
        cout << "tan90" << endl;
    }else if(a[m] == f){
        cout << m << endl;
    }else if(a[m] < f){
        fd(a, m+1, r, f);
    }else{
        fd(a, l, m-1, f);
    }
}

int main()
{
    NOTLE
    int n, q, f;
    cin >> n >> q;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < q; i++){
        cin >> f;
        fd(a, 1, n, f);
    }
}
