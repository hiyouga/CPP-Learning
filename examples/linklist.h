// linklist.h -- class definition for the linklist ADT

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef int Elemtype;

typedef struct {
	Elemtype val;
	LinkNode * nxt;
} LinkNode;

class LinkList
{
private:
	LinkNode * head;
public:
	LinkList();
	~LinkList();
	void CreateHead(Elemtype * a, int n);
	void CreateTail(Elemtype * a, int n);
	void DispList();
	int ListLength();
	bool GetList(int i, Elemtype &e);
	int FindList(Elemtype e);
	bool InsertList(int i, Elemtype e);
	bool DeleteList(int i);
	void SortList();
};

#endif

LinkList::LinkList()
{
	head = new LinkNode;
	head -> nxt = NULL;
}

LinkList::~LinkList()
{
	LinkNode * pre, * p;
	pre = head;
	p = pre -> nxt;
	while(p != NULL){
		delete pre;
		pre = p;
		p = p -> nxt;
	}
	delete pre;
}

void LinkList::CreateHead(Elemtype * a, int n)
{
	LinkNode * s;
	head -> nxt = NULL;
	for(int i = 0; i < n; i++){
		s = new LinkNode;
		s -> val = a[i];
		s -> nxt = head -> nxt;
		head -> nxt = s;
	}
}

void LinkList::CreateTail(Elemtype * a, int n)
{
	LinkNode * s, * r;
	r = head;
	for(int i = 0; i < n; i++){
		s = new LinkNode;
		s -> val = a[i];
		r -> nxt = s;
		r = s;
	}
	r -> nxt = NULL;
}

void DispList()
{
	using std::cout;
	using std::endl;
	LinkNode * p;
	p = head -> nxt;
	while(p != NULL){
		cout << p -> val << " ";
		p = p -> nxt;
	}
	cout << endl;
}

int ListLength()
{
	int i = 0;
	LinkNode * p;
	p = head;
	while(p -> nxt != NULL){
		i++;
		p = p -> nxt;
	}
	return i;
}

bool GetList(int i, Elemtype &e)
{
	int j = 0;
	LinkNode * p;
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

int FindList(Elemtype e)
{
	int i = 1;
	LinkNode * p;
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

bool InsertList(int i, Elemtype e)
{
	int j = 0;
	LinkNode * s, * p;
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
		s = new LinkNode;
		s -> val = e;
		s -> nxt = p -> nxt;
		p -> nxt = s;
		return true;
	}
}

bool DeleteList(int i)
{
	int j = 0;;
	LinkNode * q, * p;
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