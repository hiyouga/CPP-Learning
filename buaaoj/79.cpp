#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

char parse(string str, int k)
{
	int s = 0;
	for (int i = 0; i < 8; i++) {
		if (str[k+i] == '1') {
			s += (1 << (7-i));
		}
	}
	return char(s);
}

int main()
{
	char type;
	string str;
	while (cin >> type) {
		cin >> str;
		if (type == 'A') {
			for (int i = 0; i < str.length() / 8; i++) {
				cout << parse(str, i * 8);
			}
		} else {
			bool flag = true;
			map <int, int> loc;
			int temp, j_pos = 999, x_pos = 999;
			vector<int> j_loc, x_loc;
			if ((temp = str.find("jhljx")) != string::npos) {
				j_pos = temp;
			}
			if ((temp = str.find("xihang")) != string::npos) {
				x_pos = temp;
			}
			for (int i = 0; i < str.length(); i++) {
				if ((str[i] == '0' && str[i+1] == 'x') && (temp = strtol(str.c_str()+i, NULL, 16))) {
					loc.insert(pair<int, int>(i, temp));
				}
			}
			map<int, int>::iterator iter;
			for(iter = loc.begin(); iter != loc.end(); iter++){
				if (iter->first > j_pos && iter->first < x_pos) {
					j_loc.push_back(iter->second);
				}
				if (iter->first > x_pos) {
					x_loc.push_back(iter->second);
				}
			}
			if (j_loc.size() == 2) {
				cout << "jhljx("<< j_loc[0] << "," << j_loc[1] << ") ";
				flag = false;
			}
			if (x_loc.size() == 2) {
				cout << "xihang("<< x_loc[0] << "," << x_loc[1] << ")";
				flag = false;
			}
			if (flag) {
				cout << "nothing found!";
			}
		}
		cout << endl;
	}
}