// bst.h -- class definition for the binary search tree ADT

#ifndef BST_H_
#define BST_H_

template <typename T>
struct BSTNode
{
	T key;
	BSTNode * lch, * rch;
};

template <typename T>
class BSTree
{
private:
	BSTNode<T> * root;
	void Destroy(BSTNode<T> * b);
	bool SubInsert(BSTNode<T> * &p, T k);
	bool SubSearch(BSTNode<T> * b, T k);
	void SubDisp(BSTNode<T> * b);
	bool SubDelete(BSTNode<T> * &b, T k);
	void ADelete(BSTNode<T> * &p);
	void SubADelete(BSTNode<T> * p, BSTNode<T> * &t);
public:
	BSTree();
	~BSTree();
	bool Insert(T k);
	bool Create(T * a, int n);
	void Disp();
	bool Search(T k);
	bool Delete(T k);
};

#endif

template <typename T>
BSTree<T>::BSTree()
{
	root = NULL;
}

template <typename T>
BSTree<T>::~BSTree()
{
	if(root != NULL)
		Destroy(root);
}

template <typename T>
void BSTree<T>::Destroy(BSTNode<T> * b)
{
	if(b != NULL){
		Destroy(b -> lch);
		Destroy(b -> rch);
		delete b;
	}
}

template <typename T>
bool BSTree<T>::Insert(T k)
{
	return SubInsert(root, k);
}

template <typename T>
bool BSTree<T>::SubInsert(BSTNode<T> * &p, T k)
{
	if(p == NULL){
		p = new BSTNode<T>();
		p -> key = k;
		p -> lch = p -> rch = NULL;
		return true;
	}
	/*if(k == p -> key)
		return false;*/
	if(k < p -> key)
		return SubInsert(p -> lch, k);
	return SubInsert(p -> rch, k);
}

template <typename T>
bool BSTree<T>::Create(T * a, int n)
{
	for(int i = 0; i < n; i++){
		if(!SubInsert(root, a[i])) return false;
	}
	return true;
}

template <typename T>
bool BSTree<T>::Search(T k)
{
	return SubSearch(root, k);
}

template <typename T>
bool BSTree<T>::SubSearch(BSTNode<T> * b, T k)
{
	if(b == NULL)
		return false;
	if(b -> key == k)
		return true;
	if(k < b -> key)
		return SubSearch(b -> lch, k);
	else
		return SubSearch(b -> rch, k);
}

template <typename T>
void BSTree<T>::Disp()
{
	SubDisp(root);
}

template <typename T>
void BSTree<T>::SubDisp(BSTNode<T> * b)
{
	if(b != NULL){
		SubDisp(b -> lch);
		std::cout << b -> key << " ";
		SubDisp(b -> rch);
	}
}

template <typename T>
bool BSTree<T>::Delete(T k)
{
	return SubDelete(root, k);
}

template <typename T>
bool BSTree<T>::SubDelete(BSTNode<T> * &b, T k)
{
	if(b == NULL)
		return false;
	if(k < b -> key)
		return SubDelete(b -> lch, k);
	if(k > b -> key)
		return SubDelete(b -> rch, k);
	ADelete(b);
	return true;
}

template <typename T>
void BSTree<T>::ADelete(BSTNode<T> * &p)
{
	BSTNode<T> * q;
	if(p -> rch == NULL){
		q = p;
		p = p -> lch;
		delete q;
	}else if(p -> lch == NULL){
		q = p;
		p = p -> rch;
		delete q;
	}else{
		SubADelete(p, p -> lch);
	}
}

template <typename T>
void BSTree<T>::SubADelete(BSTNode<T> * p, BSTNode<T> * &t)
{
	BSTNode<T> * q;
	if(t -> rch != NULL){
		SubADelete(p, t -> rch);
	}else{
		p -> key = t -> key;
		q = t;
		t = t -> lch;
		delete q;
	}
}