#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int ack(int m, int n)
{
    if(m == 0) return n + 1;
    if(n == 0) return ack(m-1, 1);
    return ack(m-1, ack(m, n-1));
}

int main()
{
    NOTLE
    int m, n;
    cin >> m >> n;
    cout << ack(m, n) << endl;
}
