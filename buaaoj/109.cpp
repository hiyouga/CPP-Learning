#include <iostream>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 1000005

using namespace std;

int prime[MAXN];
bool check[MAXN] = {0};

int main()
{
    NOTLE

    long long n;
    long long t = 0;
    for(int i = 2; i <= MAXN; i++){
        if(!check[i]){
            prime[t++] = i;
        }
        for(int j = 0; j < t; j++){
            for(int k = 1; k * prime[j] * prime[j] < MAXN; k++){
                check[k * prime[j] * prime[j]] = true;
            }
        }
    }
    //while(cin >> n){
    for(int i = 1; i < 100; i++){
            n = i;
        t = 0;
        while(check[n]){
            while(check[n] && n % prime[t] == 0){
                n /= prime[t];
            }
            t++;
        }
        cout << n << endl;
    }
}
