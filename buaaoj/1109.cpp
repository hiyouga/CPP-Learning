#include <iostream>
#include <cstring>
#define MAXN 26
#define BORDER (x+ax >= 0 && x+ax < n && y+ay >= 0 && y+ay < n)

using namespace std;

int n;
char mat[25][25];
string ect[3][3] = {
	{"UL", "U", "UR"},
	{"L", "M", "R"},
	{"DL", "D", "DR"}
};

void bfs(int x, int y, int ax, int ay, string str, int k)
{
	if(k == str.length()-1){
		cout << x-ax*k << " " << y-ay*k << endl;
		cout << ect[ax+1][ay+1] << endl;
	}
	if(mat[x+ax][y+ay] == str[k+1] && BORDER)
		bfs(x+ax, y+ay, ax, ay, str, k+1);
}

void dec(int x, int y, string str)
{
	bfs(x, y, -1, 0, str, 0);//U
	bfs(x, y, 1, 0, str, 0);//D
	bfs(x, y, 0, -1, str, 0);//L
	bfs(x, y, 0, 1, str, 0);//R
	bfs(x, y, -1, 1, str, 0);//UR
	bfs(x, y, -1, -1, str, 0);//UL
	bfs(x, y, 1, 1, str, 0);//DR
	bfs(x, y, 1, -1, str, 0);//DL
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	string str;
	cin >> str;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(mat[i][j] == str[0])
				dec(i, j, str);
	return 0;
}