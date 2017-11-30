#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int suc = 0;

void jump(int * a, int j, int n)// j:now position n: max pos
{
	if(j == n)
		suc++;
	if(j < n){
		for (int i = 1; i <= a[j]; ++i)
		{
			jump(a, j + i, n);
		}
	}
	
}

int main()
{
	NOTLE
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	jump(a, 0, n-1);
	if (suc) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

/*
那么这个“神奇的跳跃”Plus 在哪里呢？给定一个含有 n 个数字的数组 arr，且数组中
每个元素均为非负整数。已知arr[i](1<=i<=n)代表在位置i处玩家最多可以向右移动arr[i]
步。一开始玩家在位置 1，只有跳到位置 n，他才能获胜。他能成功到达位置 n 吗？
★数据输入
第一行输入一个整数 n(1<=n<=1000)，代表终点位置。
第二行输入 n 个非负整数，数字与数字之间用空格隔开，所有输入均<=1000。
★数据输出
如果玩家能到达终点，输出“YES” （不包含引号），否则输出“NO” （不包含引号）。
5 2 3 1 1 4 YES
5 3 2 1 0 4 NO
5 3 2 2 0 0 YES
10 4 0 0 1 3 0 2 0 1 2 YES
*/