#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int MOD = 1e7+7;
long long s = 0;

int main()
{
	NOTLE

	int n;
	cin >> n;
    long long a[5] = {1, 0, 0, 0, 0};
    for(int i = 1; i < n; i++){
        a[4] += a[3];
        for(int j = 3; j > 0; j--){
            a[j] = a[j-1];
        }
        a[0] = a[4];
        /*for(int j = 0; j < 5; j++)
            cout << a[j] << ends;
        cout << endl;*/
    }
    for(int i = 0; i < 5; i++)
        s += a[i];
    cout << s % MOD << endl;
	return 0;
}
