#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE
    int k, i = 0;
    long long q = 1, p, s = 0, t = 0, n = 0;//q count
    cin >> k >> p;
    while(i < k){
        for(int j = q; j < q*10 && i < k; j++){
        	n = 0;
        	t = j;
        	while(t > 0){
        		n *= 10;
        		n += t % 10;
        		t /= 10;
        	}
        	s = s % p + (j*q*10 + n) % p;
        	i++;
        }
        q *= 10;
    }
    cout << s % p << endl;
}
