/*
Counting Inversions Problem

O(n^2)
O(nlogn)

Input:
14 7 18 3 10 19 11 23 2 25 16 17
Output:
25
*/
#include <iostream>
#include <vector>

using namespace std;

int cip_a(int * a, int n) //O(n^2)
{
	int r = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[i] > a[j])
				r++;
		}
	}
	return r;
}

int merge_cnt(int * a, int l, int m, int r)
{
	int s = 0;
	int p = l, q = m + 1;
	vector<int> v;
	while(p <= m && q <= r){
		if(a[p] <= a[q]){
			v.push_back(a[p++]);
		}else{
			s += m + 1 - p;
			v.push_back(a[q++]);
		}
	}
	while(p <= m)
		v.push_back(a[p++]);
	while(q <= r)
		v.push_back(a[q++]);
	for(int i = l; i <= r; i++)
		a[i] = v[i-l];
	return s;
}

int cip_b(int * a, int l, int r)//O(nlogn)
{
	if(l < r){
		int m = (l + r) >> 1;
		int p_1 = cip_b(a, l, m);
		int p_2 = cip_b(a, m + 1, r);
		int p_3 = merge_cnt(a, l, m, r);
		return p_1 + p_2 + p_3;
	}else{
		return 0;
	}
}
/*
T(n) = T([n/2]) + T([n/2]) + O(n), n > 1
T(n) = O(1), n = 1
*/

int main()
{
	int a[12] = {14, 7, 18, 3, 10, 19, 11, 23, 2, 25, 16, 17};
	int s = cip_a(a, 12);
	cout << s << endl;
	s = cip_b(a, 0, 11);
	cout << s << endl;
}