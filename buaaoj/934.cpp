#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1e7+7
using namespace std;

long long s = 1;

void rab(int x, int n)
{
    if(n == 0){
        return ;
    }
    if(x >= 5){
        s++;
        rab(x+1, n-1);
        rab(1, n-1);
    }else{
        rab(x+1, n-1);
        if(x+1 == 5) rab(1, n-1);
    }
}

int main()
{
	NOTLE

	int n;
	cin >> n;
	rab(1, n);
	s %= long(MOD);
	cout << s << endl;
	return 0;
}
