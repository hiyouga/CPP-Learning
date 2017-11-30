/*
 * 拱猪计分
 * 输入中已经给出计分牌数，而此程序不需要那个数据..没看清题gg
 */
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int heart(string str, int h, int dh)
{
	string q[13] = {"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13"};
	int c[13] = {-50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};
	if (h == 13) {
		if(!dh)
			return 200;
		else
			return 0;
	} else {
		for (int i = 0; i < 13; ++i)
		{
			if(str == q[i])
				return c[i];
		}
	}
}

int main()
{
	NOTLE
	int b[4], t[4];
	string s[4], buf;
	stringstream ss;
	while (true)
	{
		vector<int> c(4);
		vector< vector<string> > v(4);
		for (int i = 0; i < 4; ++i){
			//cin >> b[i];
			getline(cin, s[i]);
			t[i] = s[i].length();
		}
		if (t[0]+t[1]+t[2]+t[3] == 0)
			break;

		for (int i = 0; i < 4; ++i)
		{
			ss << s[i];
			while (ss >> buf)
				v[i].push_back(buf);
			ss.clear();
		}

		for (int i = 0; i < 4; ++i)
		{
			int p = 0,//p:double
				h = 0,//h:red
				g = 0,//g:S12
				d = 0,//d:D11
				dh = 0,//dh:full red
				flag = 0;
			for (int j = 0; j < v[i].size(); ++j)
			{
				if(v[i][j][0] == 'H') h++;
			}
			for (int j = 0; j < v[i].size(); ++j)
			{
				if(v[i][j] == "C10") p = 1;
				if(v[i][j][0] == 'H')
					c[i] += heart(v[i][j], h, dh++);
				if(v[i][j] == "S12") g = -100;
				if(v[i][j] == "D11") d = 100;
			}
			if (h == 13 && g && d)
				c[i] += 300;
			if (h != 13) {
				c[i] += d;
				c[i] += g;
			}
			if(p){
				if(c[i] == 0)
					c[i] += 50;
				else
					c[i] *= 2;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if(i != 0) cout << " ";
			if(c[i] > 0) cout << "+";
			cout << c[i];
		}
		cout << endl;
		c.clear();
		v.clear();
	}
}
/*
test data:
S12 H3 H5 H13
D11 H8 H9
C10 H1 H2 H4 H6 H7
H10 H11 H12

H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13
S12 C10
D11


H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13 S12 C10 D11
S1 S3

C8 C12 C1
*/