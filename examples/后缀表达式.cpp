#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include "stack.h"

int isp(char);
int icp(char);

int main()
{
	using namespace std;
	char temp, op, x[64];
	Stack<char> ep;
    while (cin >> x && x[0] != '=') {
        if (isdigit(x[0])) {
            cout << x;
        } else {
        	temp = x[0];
        	if (ep.isempty()) {
                ep.push(temp);
            } else {
                if (temp == ')') {
                    while (ep.get(op) && op != '(') {
                        ep.pop(op);
                        cout << op;
                    }
                    ep.pop(op);
                } else {
                    while (ep.get(op) && (isp(op) >= icp(temp))) {
                        ep.pop(op);
                        cout << op;
                    }
                    ep.push(temp);
                }
            }
        }
    }
    while (!ep.isempty()) {
    	ep.pop(op);
    	cout << op;
    }
	return 0;
}

int isp(char k)
{
    switch (k) {
    case '+':
        return 4;
    case '-':
        return 4;
    case '*':
        return 6;
    case '/':
        return 6;
    case '(':
        return 2;
    case ')':
        return 8;
    default:
        return 0;
    }
}

int icp(char k)
{
    switch (k) {
    case '+':
        return 3;
    case '-':
        return 3;
    case '*':
        return 5;
    case '/':
        return 5;
    case '(':
        return 7;
    case ')':
        return 2;
    default:
        return 0;
    }
}
