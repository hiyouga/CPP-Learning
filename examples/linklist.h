// linklist.h -- class definition for the linklist ADT

#ifndef LINKLIST_H_
#define LINKLIST_H_

template <typename T>
struct LinkNode
{
	T val;
	LinkNode<T> * nxt;
};

template <typename T>
class LinkList
{
private:
	LinkNode<T> * head;
public:
	LinkList();
	~LinkList();
	void CreateHead(T * a, int n);
	void CreateTail(T * a, int n);
	bool isempty() const;
	void DispList();
	int ListLength();
	bool GetList(int i, T &e);
	int FindList(T e);
	bool InsertList(int i, T e);
	bool DeleteList(int i);
	void SortList();
	void ReverseList();
};

#endif

template <typename T>
LinkList<T>::LinkList()
{
	head = new LinkNode<T>();
	head -> nxt = NULL;
}

template <typename T>
LinkList<T>::~LinkList()
{
	LinkNode<T> * pre, * p;
	pre = head;
	p = pre -> nxt;
	while(p != NULL){
		delete pre;
		pre = p;
		p = p -> nxt;
	}
	delete pre;
}

template <typename T>
void LinkList<T>::CreateHead(T * a, int n)
{
	LinkNode<T> * s;
	head -> nxt = NULL;
	for(int i = 0; i < n; i++){
		s = new LinkNode<T>();
		s -> val = a[i];
		s -> nxt = head -> nxt;
		head -> nxt = s;
	}
}

template <typename T>
void LinkList<T>::CreateTail(T * a, int n)
{
	LinkNode<T> * s, * r;
	r = head;
	for(int i = 0; i < n; i++){
		s = new LinkNode<T>();
		s -> val = a[i];
		r -> nxt = s;
		r = s;
	}
	r -> nxt = NULL;
}

template <typename T>
void LinkList<T>::DispList()
{
	using std::cout;
	using std::endl;
	LinkNode<T> * p;
	p = head -> nxt;
	while(p != NULL){
		cout << p -> val << " ";
		p = p -> nxt;
	}
	cout << endl;
}

template <typename T>
bool LinkList<T>::isempty()
{
	return (head->nxt == NULL);
}

template <typename T>
int LinkList<T>::ListLength()
{
	int i = 0;
	LinkNode<T> * p;
	p = head;
	while(p -> nxt != NULL){
		i++;
		p = p -> nxt;
	}
	return i;
}

template <typename T>
bool LinkList<T>::GetList(int i, T &e)
{
	int j = 0;
	LinkNode<T> * p;
	p = head;
	while(j < i && p != NULL){
		j++;
		p = p -> nxt;
	}
	if(p == NULL)
		return false;
	else {
		e = p -> val;
		return true;
	}
}

template <typename T>
int LinkList<T>::FindList(T e)
{
	int i = 1;
	LinkNode<T> * p;
	p = head -> nxt;
	while(p != NULL && p -> val != e){
		p = p -> nxt;
		i++;
	}
	if(p == NULL)
		return 0;
	else
		return i;
}

template <typename T>
bool LinkList<T>::InsertList(int i, T e)
{
	int j = 0;
	LinkNode<T> * s, * p;
	if(i < 1)
		return false;
	p = head;
	while(j < i-1 && p != NULL){
		j++;
		p = p -> nxt;
	}
	if(p == NULL)
		return false;
	else {
		s = new LinkNode<T>();
		s -> val = e;
		s -> nxt = p -> nxt;
		p -> nxt = s;
		return true;
	}
}

template <typename T>
bool LinkList<T>::DeleteList(int i)
{
	int j = 0;;
	LinkNode<T> * q, * p;
	if(i < 1)
		return false;
	p = head;
	while(j < i-1 && p != NULL){
		j++;
		p = p -> nxt;
	}
	if(p == NULL)
		return false;
	else {
		q = p -> nxt;
		if(q == NULL)
			return false;
		p -> nxt = q -> nxt;
		delete q;
		return true;
	}
}

template <typename T>
void LinkList<T>::SortList()
{
	LinkNode<T> * p;
	p = head;
	

}

template <typename T>
void LinkList<T>::ReverseList()
{
	LinkNode<T> * p, * q;
	p = head -> nxt;
	head -> nxt = NULL;
	while(p != NULL){
		q = p -> nxt;
		p -> nxt = head -> nxt;
		head -> nxt = p;
		p = q;
	}
}