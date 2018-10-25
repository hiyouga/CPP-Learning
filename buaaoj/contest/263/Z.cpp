#include <iostream>
#include <stack>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
	string str;
	stringstream ss;
	while (cin >> str) {
		ss << str;
		char c;
		long long temp, a;
		stack<long long> num;
		ss >> temp;
		num.push(temp);
		while (true) {
			c = ss.get();
			if (c == '*') {
				ss >> temp;
				a = num.top();
				num.pop();
				num.push(temp * a);
			} else if (c == '+') {
				ss >> temp;
				num.push(temp);
			} else {
				break;
			}
		}
		long long sum = 0;
		while (!num.empty()) {
			temp = num.top();
			num.pop();
			sum += temp;
		}
		cout << sum % 10000 << endl;
		ss.clear();
	}
}