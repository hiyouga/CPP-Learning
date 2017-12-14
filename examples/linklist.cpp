#include <iostream>
#include "linklist.h"

using namespace std;

int main()
{
	LinkList<int> ld;
	int elem[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ld.CreateTail(elem, 10);
	cout << ld.ListLength() << endl;
	ld.ReverseList();
	ld.DispList();
	return 0;
}