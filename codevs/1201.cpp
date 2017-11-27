#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int n;
    cin >> n;
    long long k, m, c;
    for(int i = 0; i < n; i++){
        cin >> k;
        if(i == 0){
            m = k, c = k;
            continue;
        }
        m = m>k ? m : k;
        c = c<k ? c : k;
    }
    cout << c << " " << m << endl;
}
