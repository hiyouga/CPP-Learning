#include <iostream>
#include <algorithm>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int n, m, s = 0, x = 0;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int c = unique(a, a+n)-a;
    int d = unique(b, b+m)-b;
    int p = 0, q = 0;
    while(p < c && q < d){
        if(a[p] == b[q]){
            cout << a[p] << " ";
            x++, p++, q++;
        }else if(a[p] > b[q]){
            q++;
        }else{
            p++;
        }
    }
    if(!x) cout << "Intersection set empty!" << endl;
    return 0;
}
