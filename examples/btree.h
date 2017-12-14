// btree.h -- class definition for the binary tree ADT

#ifndef BTREE_H_
#define BTREE_H_

template <typename T>
struct BTNode
{
	T val;
	BTNode<T> * ltd, * rtd;
};

template <typename T>
class BTree
{
private:
	enum {MAXSIZE = 999};
	BTNode<T> * root;
	void DestroyBTree(BTNode<T> * r);
	void SubDispBTNode(BTNode<T> * t);
	BTNode<T> * SubFindNode(BTNode<T> * t, T x);
	int SubBTNodeHeight(BTNode<T> * t);
	void SubPreOrder(BTNode<T> * t);
	void SubInOrder(BTNode<T> * t);
	void SubPostOrder(BTNode<T> * t);
public:
	BTree();
	~BTree();
	void CreateBTree(char * str);
	void DispBTree();
	BTNode<T> * FindNode(T x);
	int BTNodeHeight();
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
};

#endif

template <typename T>
BTree<T>::BTree()
{
	root = NULL;
}

template <typename T>
BTree<T>::~BTree()
{
	DestroyBTree(root);
}

template <typename T>
void BTree<T>::DestroyBTree(BTNode<T> * r)
{
	if(r != NULL){
		DestroyBTree(r -> ltd);
		DestroyBTree(r -> rtd);
		delete r;
	}
}

template <typename T>
void BTree<T>::CreateBTree(char * str)
{
	BTNode<T> * St[MAXSIZE], * p;
	int top = -1, k = 0, j = 0;
	char ch;
	while(str[j] != '\0'){
		ch = str[j];
		switch(ch)
		{
			case '(':St[++top] = p; k = 1; break;
			case ')':top--; break;
			case ',':k = 2; break;
			default:
				p = new BTNode<T>();
				p -> ltd = p -> rtd = NULL;
				p -> val = ch;
				if(root == NULL){
					root = p;
				}else{
					switch(k)
					{
						case 1:St[top] -> ltd = p; break;
						case 2:St[top] -> rtd = p; break;
					}
				}
				break;
		}
		j++;
	}
}

template <typename T>
void BTree<T>::DispBTree()
{
	SubDispBTNode(root);
}

template <typename T>
void BTree<T>::SubDispBTNode(BTNode<T> * t)
{
	using std::cout;
	if(t != NULL){
		cout << t -> val;
		if(t -> ltd != NULL || t -> rtd != NULL){
			cout << "(";
			SubDispBTNode(t -> ltd);
			if(t -> rtd != NULL)
				cout << ",";
			SubDispBTNode(t -> rtd);
			cout << ")";
		}
	}
}

template <typename T>
BTNode<T> * BTree<T>::FindNode(T x)
{
	return SubFindNode(root, x);
}

template <typename T>
BTNode<T> * BTree<T>::SubFindNode(BTNode<T> * t, T x)
{
	BTNode<T> * p;
	if(t == NULL)
		return NULL;
	if(t -> val == x)
		return t;
	p = SubFindNode(t -> ltd, x);
	if(p != NULL) return p;
	return SubFindNode(t -> rtd, x);
}

template <typename T>
int BTree<T>::BTNodeHeight()
{
	return SubBTNodeHeight(root);
}

template <typename T>
int BTree<T>::SubBTNodeHeight(BTNode<T> * t)
{
	int lh, rh;
	if(t == NULL) return 0;
	lh = SubBTNodeHeight(t -> ltd);
	lh = SubBTNodeHeight(t -> rtd);
	return (lh>rh)?(lh+1):(rh+1);
}

template <typename T>
void BTree<T>::PreOrder()
{
	SubPreOrder(root);
}

template <typename T>
void BTree<T>::SubPreOrder(BTNode<T> * t)
{
	if(t != NULL){
		std::cout << t -> val;
		SubPreOrder(t -> ltd);
		SubPreOrder(t -> rtd);
	}
}

template <typename T>
void BTree<T>::InOrder()
{
	SubInOrder(root);
}

template <typename T>
void BTree<T>::SubInOrder(BTNode<T> * t)
{
	if(t != NULL){
		SubInOrder(t -> ltd);
		std::cout << t -> val;
		SubInOrder(t -> rtd);
	}
}

template <typename T>
void BTree<T>::PostOrder()
{
	SubPostOrder(root);
}

template <typename T>
void BTree<T>::SubPostOrder(BTNode<T> * t)
{
	if(t != NULL){
		SubPostOrder(t -> ltd);
		SubPostOrder(t -> rtd);
		std::cout << t -> val;
	}
}

template <typename T>
void BTree<T>::LevelOrder()
{
	BTNode<T> * p, * qu[MAXSIZE];
	int fr = 0, re = 0;
	re++;
	qu[re] = root;
	while(fr != re){
		fr = (fr + 1) % MAXSIZE;
		p = qu[fr];
		std::cout << p -> val;
		if(p -> ltd != NULL){
			re = (re + 1) % MAXSIZE;
			qu[re] = p -> ltd;
		}
		if(p -> rtd != NULL){
			re = (re + 1) % MAXSIZE;
			qu[re] = p -> rtd;
		}
	}
}