#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
	char str[80] = "+(*(/(A,^(B,C)),D),E)";
	BTree<char> bt;
	bt.CreateBTree(str);
	cout << bt.BTNodeHeight() << endl;
	bt.DispBTree();
	cout << endl;
	bt.PreOrder();
	cout << endl;
	bt.InOrder();
	cout << endl;
	bt.PostOrder();
	cout << endl;
	bt.LevelOrder();
	cout << endl;
	return 0;
}
