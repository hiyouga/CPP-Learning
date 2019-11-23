#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int y, b, r;
    cin >> y >> b >> r;
    int c = 1;
    while (c < y && c+1 < b && c+2 < r) {
        c++;
    }
    cout << c*3+3 << endl;
    return 0;
}
