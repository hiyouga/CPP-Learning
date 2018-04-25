/*
Polynomial Multiplication Problem
O(n^2)
Input:
2 5 3 1 -1
1 2 2 3 6
Output:
2 9 17 23 34 39 19 3 -6
*/
#include <iostream>
#include <cstring>

using namespace std;

void pmp_a(int * a, int * b, int * c, int l) //O(n^2)
{
	for(int i = 0; i < l; i++){
		for(int j = 0; j < l; j++){
			c[i + j] += a[i] * b[j];
		}
	}
}

void pmp_b(int * a, int * b, int * c, int l)
{
	if(l <= 2){
		c[0] = a[0] * b[0];
		c[1] = a[0] * b[1] + a[1] * b[0];
		c[2] = a[1] * b[1];
	}else{

		pmp_b(a, b, d[1], l/2);
	}
}

int main()
{
	int a[3] = {1, 2, 3};
	int b[3] = {3, 2, 2};
	int c[5];
	memset(c, 0, sizeof(c));
	pmp_a(a, b, c, 3);
	for(int i = 0; i < 5; i++)
		cout << c[i] << " ";
	cout << endl;
}