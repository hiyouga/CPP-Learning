#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100];
int fd(int l,int r,int v);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k,f;
    cin>>n;//输入对应编号0~n-1节点的颜色
    for(int p=0;p<n;p++){
        cin>>a[p];
    }
    sort(a,a+n);//对a排序
    int l=unique(a,a+n)-a;
    cin>>k;
    f = fd(0,l,k);
    cout<<f<<endl;

}
int fd(int l,int r,int v){//v：要找的数字，l：左边界，r：右边界
	if(l+1 == r){
		return l;//若左界+1=右界
	}else{
		int m = (l+r)/2;//取中点middle
		if(v<a[m]){
			return fd(l,m,v);
		}else{
			return fd(m,r,v);
		}
	}
}
