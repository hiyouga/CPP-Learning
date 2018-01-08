#include <iostream>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    long long a, b, x, y, z, blu, yel;
    cin >> a >> b;
    cin >> x >> y >> z;
    yel = x * 2 + y - a;
    blu = y + z * 3 - b;
    if(yel < 0) yel = 0;
    if(blu < 0) blu = 0;
    cout << yel + blu << endl;

    return 0;
}
