/* 
 Author: 郑耀威
 Result: AC	Submission_id: 483450
 Created at: Sat Dec 09 2017 21:25:20 GMT+0800 (CST)
 Problem_id: 446	Time: 7	Memory: 2688
*/

#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int sev(unsigned long long x)
{
	if(x % 7 == 0)
		return 1;
	while(x > 0){
		if(x % 10 == 7)
			return 1;
		x /= 10;
	}
	return 0;
}

int main()
{
	NOTLE

	int n, i;
	unsigned long long p;
	cin >> n >> i >> p;
	p = p + i - 1;
	while(!sev(p))
		p += n;
	cout << p << endl;
	return 0;
}