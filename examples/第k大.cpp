#include <iostream>

using namespace std;

int Partition(int * a, int l, int r)
{
	int temp = a[l];
	while(l != r){
		while(l < r && a[r] <= temp){
			r--;
		}
		a[l] = a[r];
		while(l < r && a[l] >= temp){
			l++;
		}
		a[r] = a[l];
	}
	a[l] = temp;
	return l;
}

void findk(int * a, int l, int r, int k)
{
	int mid = Partition(a, l, r);
	if(mid == k - 1){
		cout << a[mid] << endl;
	}else if(mid > k - 1){
		findk(a, l, mid-1, k);
	}else{
		findk(a, mid+1, r, k);
	}
}

int main()
{
	int n, k;
	while(cin >> n >> k){
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		findk(a, 0, n-1, k);
		for(int i = 0; i < n; i++)
			cout << a[i] << ends;
		cout << endl;
	}
	return 0;
}