#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0, x[2][n];
    for(int i = 0; i < n; i++)
        cin >> x[0][i];
    for(int i = 0; i < n; i++)
        cin >> x[1][i];
    for(int i = 0; i < n; i++)
        s += x[0][i] * x[1][i];
    cout << s << endl;
}
