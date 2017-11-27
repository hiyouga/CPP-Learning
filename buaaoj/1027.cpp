#include <iostream>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int n, d, p = 0, flag;
    cin >> n;
    int a[n], k[n];
    memset(k, 0, sizeof(k));
    for(int i = 0; i < n; i++){
        cin >> d;
        flag = 1;
        for(int j = 0; j < i && flag; j++){
            if(d == a[j]){
                k[j]++;
                flag = 0;
            }
        }
        if(flag) a[p++] = d;
    }
    int t = 0;
    while(k[t]!=0) t++;
    cout << a[t] << endl;
}
