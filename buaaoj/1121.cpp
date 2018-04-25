#include <iostream>

using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m){
        int d[n], h[n];
        for(int i = 0; i < n; i++){
            cin >> d[i] >> h[i];
        }
        int dp[m+1] = {0};
        for(int i = 0; i < n; i++){
            for(int j = m; j >= d[i]; j--){
                dp[j] = max(dp[j], dp[j-d[i]]+h[i]);
                cout << j << ends << dp[j] << endl;
            }
        }
        cout << dp[m] << endl;
    }
}
