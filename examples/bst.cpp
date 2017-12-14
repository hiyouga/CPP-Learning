#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
	int num[12] = {9,6,23,1,94,21,48,36,4,9,87,55};
	int add[5] = {50,31,77,3,41};
	BSTree<int> bst;
	bst.Create(num, 12);
	for(int i = 0; i < 5; i++)
		bst.Insert(add[i]);
	bst.Delete(36);
	bst.Disp();
	return 0;
}