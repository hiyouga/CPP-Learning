#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int neededNumber(vector<long long> &A, long long n) {
	sort(begin(A), end(A));
	int ans = 0;
	long long curMax = 0;
	//vector<long long> ans;
	for (long long x : A) {
		while (curMax < n && x > curMax + 1) {
			//ans.push_back(curMax + 1);
			ans++;
			curMax += curMax + 1;
		}
		if (curMax == n) return ans;
		curMax += x;
	}
	while (curMax < n) {
		//ans.push_back(curMax + 1);
		ans++;
		curMax += curMax + 1;
	}
	return ans;
}

int main()
{
	long long n, m;
	while (cin >> n >> m) {
		vector<long long> wgt(n);
		for (int i = 0; i < n; i++)
			cin >> wgt[i];
		cout << neededNumber(wgt, m) << endl;
	}
}