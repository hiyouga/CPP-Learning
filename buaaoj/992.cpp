#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int a[4], b[4];
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    for(int i = 0; i < 4; i++)
        cin >> b[i];
    cout << a[0] * b[0] + a[1] * b[2] << " "
         << a[0] * b[1] + a[1] * b[3] << " "
         << a[2] * b[0] + a[3] * b[2] << " "
         << a[2] * b[1] + a[3] * b[3] << endl;
    return 0;
}
