#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 1850000

using namespace std;

int main()
{
    NOTLE
    int k, d = 1, v[100];
    double r, s = 1;
    cin >> k;
    for(int i = 2; d <= k; i++){
        r = s;
        s += 1.0/i;
        if(s>d && r<=d){
            v[d] = i;
            d++;
        }
    }
    cout << v[k];
}
