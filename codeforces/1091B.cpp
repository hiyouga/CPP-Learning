#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int n;
    cin >> n;
    int x, y, dx = 0, dy = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        dx += x, dy += y;
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        dx += x, dy += y;
    }
    cout << dx / n << ' ' << dy / n << endl;
    return 0;
}
