///stdafx
#include <algorithm> ///STL通用算法
#include <bitset> ///STL位集容器
#include <cassert>
#include <cctype> ///字符处理
#include <cfloat> ///浮点数处理
#include <ciso646> ///运算符宏
#include <climits> ///数据类型最值常量
#include <clocale> ///本地化函数
#include <cmath> ///数学函数
#include <complex> ///复数类
#include <csignal> ///信号机制支持
#include <csetjmp> ///异常处理支持
#include <cstddef> ///常用常量
#include <cstdio> ///输入输出函数
#include <cstdlib> ///杂项函数
#include <cstring> ///字符串处理
#include <ctime> ///时间函数
#include <cwchar> ///宽字符处理及输入输出
#include <cwctype> ///宽字符分类
#include <deque> ///STL双端队列容器
#include <fstream> ///文件输入输出流
#include <functional> ///STL定义运算函数
#include <list> ///STL线性列表容器
#include <locale> ///本地化特定信息
#include <map> ///STL映射容器
#include <memory> ///STL内存分配
#include <new> ///动态内存分配
#include <numeric> ///STL数字操作
#include <iomanip> ///参数化输入输出
#include <ios> ///基本输入输出支持
#include <iostream> ///基本输入输出流
#include <iterator> ///STL迭代器
#include <queue> ///STL队列容器
#include <set> ///STL集合容器
#include <sstream> ///字符串流
#include <stack> ///STL堆栈容器
#include <streambuf> ///底层输入输出
#include <utility> ///STL通用模板
#include <vector> ///STL动态数组
///C++输入输出优化
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///模除逆元
const long long TWO = 500000004, THR = 333333336, FIV = 400000003, MOD = 1000000007;
///无穷大
const int inf = 0x3f3f3f3f;
///C++STL操作
///vector（向量）
vector<int> vec;
vector[0]; ///使用下标访问元素
vec.front(); ///取vec中的第一个元素
vec.back(); ///取vec中的最末一个元素
vec.push_back(x); ///在向量末尾加入元素x
vec.pop_back(); ///删除末尾元素，同时向量空间减少1
vec.insert(vec.begin() + i, a); ///在第i+1个元素前边插入元素a
vec.erase(vec.begin() + i); ///删除第i+1个元素
vec.size(); ///取向量大小
vec.clear(); ///清空向量
reverse(vec.begin(), vec.end()); ///将向量翻转
sort(vec.begin(), vec.end()); ///排序
vec.resize(n,1); ///改变当前向量大小为n，新增加的元素赋值为1
vec.empty(); ///判断向量是否为空，为空返回1，不为空返回0
swap(vec & v); ///交换向量vec和v的值
vec.max_size(); ///返回vec的最大长度
///set（集合）
set<int> s;
s.clear(); ///清除所有元素
s.count(x); ///返回集合中元素x的数目，由于set中元素是唯一的，所以用来判断元素是否存在
s.empty(); ///判断当前集合是否为空
s.erase(x); ///删除集合中元素x
s.insert(x); ///向集合中插入元素x
s.size(); ///返回集合的大小
s.find(x); ///在集合中查找元素x，返回的是指向x所在位置的迭代器
///stack（堆栈）
stack<int> stk;
stk.empty(); ///判断栈是否为空
stk.push(); ///向当前堆栈中加入元素
stk.pop(); ///将最后放入的元素弹出
stk.size(); ///返回堆栈的大小
stk.top(); ///返回堆栈顶部元素
///map（映射）
map<int,int> mp;
map<pair<int,int> ,int> mpair;
mp[0]=x; ///利用数组方式插入数据，0是键，x是值
mp.at(0)=x; ///利用at执行插入操作
mp.insert(make_pair(1, x)); ///利用insert插入pair(键，值)数据
mp.emplace(make_pair(1, x)); ///在映射中不存在主键1时执行插入操作
mp.size(); ///返回mp的大小
mp<int,int> ::iterator iter; ///定义迭代器
for(it = mp.begin(); it != mp.end(); it++); ///映射遍历的方式，利用迭代器实现
mp.count(1); ///统计键为1的元素存在的映射数，存在返回1，不存在返回0
mp.erase(iter); ///根据迭代器删除元素
mp.clear(); ///清空映射
mp.epty(); ///判断映射是否为空
mp.find(1); ///根据键1查找元素，找到以后返回迭代器
mp.rbegin(), mp.rend(); ///返回反向迭代器
lower_bound(1); ///返回查找的键1的下界，即闭区间，返回的是迭代器
upper_bound(1); ///返回查找的键1的上界，即开区间，返回的是迭代器
mp.swap(m); ///将mp和m进行交换
///queue（队列）
queue<int> q;
q.push(x); ///入队
q.pop(); ///出队
q.front(); ///访问队首元素
q.back(); ///访问队尾元素
q.empty(); ///判断队列是否为空
q.size(); ///返回队列的大小
///algorithm
void for_each(begin, end, visit); ///遍历容器
::iterator min_element(begin, end); ///最小值
::iterator max_element(begin, end); ///最大值
void sort(begin, end, cmp); ///排序
void copy(begin, end, place); ///复制
int unique(begin, end); ///升序去重
bool binary_search(begin, end, value); ///升序二分查找
///快速幂
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
///最大公约数
int gcd(int x, int y)
{
    if(x > y) return gcd(y, x);
    if(x == 0) return y;
    return gcd(y % x, x);
}
///博弈论
bool judge(int n)
{
    int k; ///步长
    if(n == 0) ///胜利条件
        return false;
    for(int i = k; i > 0; i--) ///选择枝
        if(judge(n-k) == false)
            return true;
    return false;
}
///叉乘
void cross(Point m, Point n, Point &v)
{
    v.x = m.y*n.z - m.z*n.y;
    v.y = m.z*n.x - m.x*n.z;
    v.z = m.x*n.y - m.y*n.x;
}
///点在多边形内
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
///字符串与数字相互转换
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
///归并排序
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
///快速排序
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
///汉诺塔
void hanoi(int n, char a, char b, char c){
    if(n >= 1){
        hanoi(n-1, a, c, b);
        cout << a << " to " << c << endl;
        hanoi(n-1, b, a, c);
    }
}
///贪心 活动选择
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
///动态规划 钢条切割
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
///动态规划 LCS
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
///单向链表
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
///二叉搜索树
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
///计算行列式
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
///素数线性筛
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
