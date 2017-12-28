#include <iostream>
#include <stack>

using namespace std;

int n, k, a[1<<18], p = 0;
stack<int> S;

main()
{
	cin >> n >> k;
	S.push(n+1);
	for(int i = 0; i < k; i++)
	{
		cin >> a[i];
		if(!S.empty() && S.top() < a[i])
		{
			cout << -1 << endl;
			return 0;
		}
		S.push(a[i]);
		while(!S.empty() && S.top() == p+1)
		{
			p++;
			S.pop();
		}

	}
	for(int i = 0;i < k; i++){
        if(i != 0) cout << " ";
        cout << a[i];
	}
	int cnt = k;
	while(!S.empty())
	{
		int w = S.top();
		S.pop();
		for(int i = w-1; i > p; i--)
            cout << " " << i;
        p = w;
	}
}
