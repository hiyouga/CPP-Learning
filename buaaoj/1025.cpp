#include <iostream>
#include <iomanip>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n = 0;
    double a[10], s = 0;
    for(int i = 0; i < 10; i++){
        cin >> a[i];
        s += a[i];
    }
    s /= 10;
    for(int i = 0; i < 10; i++){
        if(a[i] > s) n++;
    }
    cout << fixed << setprecision(3) << s << endl;
    cout << n << endl;
}
