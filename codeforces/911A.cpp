#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    const int INF = 0x3f3f3f3f;
    int n;
    cin >> n;
    unsigned int low = INF, a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        low = min(a[i], low);
    }
    int pre = -INF, lst = 0, dis = INF;
    for(int i = 0; i < n; i++){
        if(low == a[i]){
            lst = i;
            dis = min(lst - pre, dis);
            pre = lst;
        }
    }
    cout << dis << endl;
    return 0;
}
