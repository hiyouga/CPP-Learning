///stdafx
#include <algorithm> ///STLͨ���㷨
#include <bitset> ///STLλ������
#include <cassert>
#include <cctype> ///�ַ�����
#include <cfloat> ///����������
#include <ciso646> ///�������
#include <climits> ///����������ֵ����
#include <clocale> ///���ػ�����
#include <cmath> ///��ѧ����
#include <complex> ///������
#include <csignal> ///�źŻ���֧��
#include <csetjmp> ///�쳣����֧��
#include <cstddef> ///���ó���
#include <cstdio> ///�����������
#include <cstdlib> ///�����
#include <cstring> ///�ַ�������
#include <ctime> ///ʱ�亯��
#include <cwchar> ///���ַ������������
#include <cwctype> ///���ַ�����
#include <deque> ///STL˫�˶�������
#include <fstream> ///�ļ����������
#include <functional> ///STL�������㺯��
#include <list> ///STL�����б�����
#include <locale> ///���ػ��ض���Ϣ
#include <map> ///STLӳ������
#include <memory> ///STL�ڴ����
#include <new> ///��̬�ڴ����
#include <numeric> ///STL���ֲ���
#include <iomanip> ///�������������
#include <ios> ///�����������֧��
#include <iostream> ///�������������
#include <iterator> ///STL������
#include <queue> ///STL��������
#include <set> ///STL��������
#include <sstream> ///�ַ�����
#include <stack> ///STL��ջ����
#include <streambuf> ///�ײ��������
#include <utility> ///STLͨ��ģ��
#include <vector> ///STL��̬����
///C++��������Ż�
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///ģ����Ԫ
const long long TWO = 500000004, THR = 333333336, FIV = 400000003, MOD = 1000000007;
///�����
const int inf = 0x3f3f3f3f;
///C++STL����
///vector��������
vector<int> vec;
vector[0]; ///ʹ���±����Ԫ��
vec.front(); ///ȡvec�еĵ�һ��Ԫ��
vec.back(); ///ȡvec�е���ĩһ��Ԫ��
vec.push_back(x); ///������ĩβ����Ԫ��x
vec.pop_back(); ///ɾ��ĩβԪ�أ�ͬʱ�����ռ����1
vec.insert(vec.begin() + i, a); ///�ڵ�i+1��Ԫ��ǰ�߲���Ԫ��a
vec.erase(vec.begin() + i); ///ɾ����i+1��Ԫ��
vec.size(); ///ȡ������С
vec.clear(); ///�������
reverse(vec.begin(), vec.end()); ///��������ת
sort(vec.begin(), vec.end()); ///����
vec.resize(n,1); ///�ı䵱ǰ������СΪn�������ӵ�Ԫ�ظ�ֵΪ1
vec.empty(); ///�ж������Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
swap(vec & v); ///��������vec��v��ֵ
vec.max_size(); ///����vec����󳤶�
///set�����ϣ�
set<int> s;
s.clear(); ///�������Ԫ��
s.count(x); ///���ؼ�����Ԫ��x����Ŀ������set��Ԫ����Ψһ�ģ����������ж�Ԫ���Ƿ����
s.empty(); ///�жϵ�ǰ�����Ƿ�Ϊ��
s.erase(x); ///ɾ��������Ԫ��x
s.insert(x); ///�򼯺��в���Ԫ��x
s.size(); ///���ؼ��ϵĴ�С
s.find(x); ///�ڼ����в���Ԫ��x�����ص���ָ��x����λ�õĵ�����
///stack����ջ��
stack<int> stk;
stk.empty(); ///�ж�ջ�Ƿ�Ϊ��
stk.push(); ///��ǰ��ջ�м���Ԫ��
stk.pop(); ///���������Ԫ�ص���
stk.size(); ///���ض�ջ�Ĵ�С
stk.top(); ///���ض�ջ����Ԫ��
///map��ӳ�䣩
map<int,int> mp;
map<pair<int,int> ,int> mpair;
mp[0]=x; ///�������鷽ʽ�������ݣ�0�Ǽ���x��ֵ
mp.at(0)=x; ///����atִ�в������
mp.insert(make_pair(1, x)); ///����insert����pair(����ֵ)����
mp.emplace(make_pair(1, x)); ///��ӳ���в���������1ʱִ�в������
mp.size(); ///����mp�Ĵ�С
mp<int,int> ::iterator iter; ///���������
for(it = mp.begin(); it != mp.end(); it++); ///ӳ������ķ�ʽ�����õ�����ʵ��
mp.count(1); ///ͳ�Ƽ�Ϊ1��Ԫ�ش��ڵ�ӳ���������ڷ���1�������ڷ���0
mp.erase(iter); ///���ݵ�����ɾ��Ԫ��
mp.clear(); ///���ӳ��
mp.epty(); ///�ж�ӳ���Ƿ�Ϊ��
mp.find(1); ///���ݼ�1����Ԫ�أ��ҵ��Ժ󷵻ص�����
mp.rbegin(), mp.rend(); ///���ط��������
lower_bound(1); ///���ز��ҵļ�1���½磬�������䣬���ص��ǵ�����
upper_bound(1); ///���ز��ҵļ�1���Ͻ磬�������䣬���ص��ǵ�����
mp.swap(m); ///��mp��m���н���
///queue�����У�
queue<int> q;
q.push(x); ///���
q.pop(); ///����
q.front(); ///���ʶ���Ԫ��
q.back(); ///���ʶ�βԪ��
q.empty(); ///�ж϶����Ƿ�Ϊ��
q.size(); ///���ض��еĴ�С
///algorithm
void for_each(begin, end, visit); ///��������
::iterator min_element(begin, end); ///��Сֵ
::iterator max_element(begin, end); ///���ֵ
void sort(begin, end, cmp); ///����
void copy(begin, end, place); ///����
int unique(begin, end); ///����ȥ��
bool binary_search(begin, end, value); ///������ֲ���
///������
long long pow_c(long long a, long long b, long long m) {
	long long ret = 1;
	while (b > 0) {
		if(b & 1)
			ret = (ret * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return ret;
}
///���Լ��
int gcd(int x, int y)
{
    if(x > y) return gcd(y, x);
    if(x == 0) return y;
    return gcd(y % x, x);
}
///������
bool judge(int n)
{
    int k; ///����
    if(n == 0) ///ʤ������
        return false;
    for(int i = k; i > 0; i--) ///ѡ��֦
        if(judge(n-k) == false)
            return true;
    return false;
}
///���
void cross(Point m, Point n, Point &v)
{
    v.x = m.y*n.z - m.z*n.y;
    v.y = m.z*n.x - m.x*n.z;
    v.z = m.x*n.y - m.y*n.x;
}
///���ڶ������
bool inpolygon(vector<Point> polygon, Point p)
{
       int cross = 0;
       for (int i = 0; i < 8; i++)
       {
              Point p1 = polygon[i];
              Point p2 = polygon[(i + 1) % 8];
              if(p1.y == p2.y) continue;
              if(p.y <= min(p1.y, p2.y)) continue;
              if(p.y >= max(p1.y, p2.y)) continue;
              double x = (double)(p.y - p1.y) * (double)(p2.x - p1.x) / (double)(p2.y - p1.y) + p1.x;
              if(x > p.x) cross++;
       }
       return (cross % 2 == 1);
}
///�ַ����������໥ת��
string i2s(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}
int s2i(string s)
{
    int n;
    stringstream ss(s);
    ss >> n;
    return n;
}
///�鲢����
int a[MAXSIZE], temp[MAXSIZE];
void Merge(int * f, int lt, int mid, int rt)
{
    int p = lt;
    int q = mid + 1;
    int k = lt;
    while(p <= mid && q <= rt){
        if(f[p] < f[q]){
            temp[k++] = f[p++];
        }else{
            temp[k++] = f[q++];
        }
    }
    while(p <= mid)
        temp[k++] = f[p++];
    while(q <= rt)
        temp[k++] = f[q++];
    for(int i = lt; i <= rt ;i++){
        f[i] = temp[i];
    }
}
void MergeSort(int * f, int lt, int rt)
{
    if(lt < rt){
        int mid = (lt + rt) / 2;
        MergeSort(f, lt, mid);
        MergeSort(f, mid+1, rt);
        Merge(f, lt, mid, rt);
    }
}
///��������
int Partition(int * f, int lt, int rt)
{
    int t = f[rt], i = lt - 1;
    for(int j = lt; j < rt; j++){
        if(f[j] <= t){
            i++;
            swap(f[i], f[j]);
        }
    }
    swap(f[i+1], f[rt]);
    return i + 1;
}
void QuickSort(int * f, int lt, int rt)
{
    if(lt < rt){
        int mid = Partition(f, lt, rt);
        QuickSort(f, lt, mid-1);
        QuickSort(f, mid+1, rt);
    }
}
///��ŵ��
void hanoi(int n, char a, char b, char c){
    if(n >= 1){
        hanoi(n-1, a, c, b);
        cout << a << " to " << c << endl;
        hanoi(n-1, b, a, c);
    }
}
///̰�� �ѡ��
void greedy_act_set (int * s, int * f, int n)
{
	int k = 1;
	cout << k << endl;
	for (int m = 2; m <= n; m++) {
		if (s[m] >= f[k]) {
			cout << m << endl;
			k = m;
		}
	}
}
///��̬�滮 �����и�
void ext_cutpod(int * t, int * p, int n)
{
    int r[n+1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = -1;
        for (int i = 1; i <= j; i++) {
            if (p[i-1] + r[j-i] > q) {
                q = p[i-1] + r[j-i];
                t[j] = i;
            }
        }
        r[j] = q;
    }
}
///��̬�滮 LCS
#define MAXSIZE 1000
char b[MAXSIZE][MAXSIZE], c[MAXSIZE][MAXSIZE];
void lcs_length(string x, string y)
{
	int m = x.length(), n = y.length();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(x[i-1] == y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 2;//leftup
			} else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 3;//up
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = 1;//left
			}
		}
	}
}
void print_lcs(string x, int i, int j)
{
	if(i == 0 || j == 0) return;
	if (b[i][j] == 2) {
		print_lcs(x, i-1, j-1);
		cout << x[i-1];
	} else if (b[i][j] == 3) {
		print_lcs(x, i-1, j);
	} else {
		print_lcs(x, i, j-1);
	}
}
///��������
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
bool LinkList<T>::isempty() const
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
	LinkNode<T> * p, * q, * s;
	T temp;
	for(p = head->nxt; p->nxt != NULL; p = p->nxt){
		s = p;
		for(q = p->nxt; q != NULL; q = q->nxt){
			if(q->val < s->val) s = q;
		}
		if(s != p){
			temp = p -> val;
			p -> val = s -> val;
			s -> val = temp;
		}
	}
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
///����������
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
///��������ʽ
#define MAXN 20
int det(int a[][MAXN], int n)
{
	if(n == 1) return a[0][0];
	int s = 0, now = 1;
	int b[MAXN][MAXN];
	for(int k = 0; k < n; k++) {
		for(int i = 1; i < n; i++){
			int sit = 0;
			for(int j = 0; j < n; j++){
				if(j == k) continue;
				b[i-1][sit++] = a[i][j];
			}
		}
		s += now * a[0][k] * det(b, n-1);
		now *= -1;
	}
	return s;
}
///��������ɸ
vector<int> prime(n);
vector<bool> check(n, 0);
for(int i = 2; i <= n; i++){
    if(!check[i]){
        prime[t++] = i;
    }
    for(int j = 0; j < t; j++){
        if(i * prime[j] > n) break;
        check[i * prime[j]] = 1;
        if(i % prime[j] == 0) break;
    }
}
