/*
Maximum Contiguous Subarray Problem

O(n^2)
O(nlogn)
O(n)

Input:
-3 2 1 -4 5 2 -1 3 -1
Output:
9
*/
#include <iostream>

using namespace std;

int mcs_a(int * a, int n) //O(n^2)
{
	int v_m = a[0];
	for(int i = 0; i < n; i++){
		int v = 0;
		for(int j = i; j < n; j++){
			v += a[j];
			v_m = max(v, v_m);
		}
	}
	return v_m;
}

int mcs_mid(int * a, int s, int m, int t)
{
	int m_l = a[m];
	int sum = a[m];
	for(int i = m-1; i >= s; i--){
		sum += a[i];
		m_l = max(m_l, sum);
	}
	int m_r = a[m+1];
	sum = a[m+1];
	for(int i = m+2; i < t; i++){
		sum += a[i];
		m_r = max(m_r, sum);
	}
	return m_l + m_r;
}

int mcs_b(int * a, int s, int t) //O(nlogn)
{
	if(s == t)
		return a[s];
	else{
		int m = (s + t) >> 1;
		int m_l = mcs_b(a, s, m);
		int m_r = mcs_b(a, m+1, t);
		int m_c = mcs_mid(a, s, m, t);
		return max(max(m_l, m_c), m_r);
	}
}
/*
T(n) = 2T(n/2) + n, n > 1
T(n) = 1, n = 1		
*/

int mcs_c(int * a, int n) //O(n)
{
	int sum_cur = a[0];
	int max_sum = a[0];
	for(int i = 0; i < n; i++){
		if(sum_cur < 0){
			sum_cur = a[i];
		}else{
			sum_cur += a[i];
		}
		max_sum = max(max_sum, sum_cur);
	}
	return max_sum;
}

int main()
{
	int a[9] = {-3, 2, 1, -4, 5, 2, -1, 3, -1};
	int s = mcs_a(a, 9);
	cout << s << endl;
	s = mcs_b(a, 0, 8);
	cout << s << endl;
	s = mcs_c(a, 9);
	cout << s << endl;
}