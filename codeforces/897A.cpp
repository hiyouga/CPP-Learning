#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int n, m, l, r;
    cin >> n >> m;
    char c1, c2, a[n+5];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r >> c1 >> c2;
        for(int j = l; j <= r; j++){
            if(a[j] == c1) a[j] = c2;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}
