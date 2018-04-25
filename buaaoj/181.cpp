#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, k;
	while(cin >> n >> k){
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		set<int> iset(a, a+n);
		set<int>::iterator ite = iset.end();
		while(k--) ite--;
		cout << *ite << endl;
	}
	return 0;
}