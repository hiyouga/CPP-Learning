#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int s;
	for(int i = 2; i < 1000; i++){
		s = 0;
		for(int j = 1; j < i; j++){
			if(i % j == 0)
				s += j;
		}
		if(s == i)
			cout << i << endl;
	}
}