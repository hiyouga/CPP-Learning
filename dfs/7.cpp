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
    cin>>n;//�����Ӧ���0~n-1�ڵ����ɫ
    for(int p=0;p<n;p++){
        cin>>a[p];
    }
    sort(a,a+n);//��a����
    int l=unique(a,a+n)-a;
    cin>>k;
    f = fd(0,l,k);
    cout<<f<<endl;

}
int fd(int l,int r,int v){//v��Ҫ�ҵ����֣�l����߽磬r���ұ߽�
	if(l+1 == r){
		return l;//�����+1=�ҽ�
	}else{
		int m = (l+r)/2;//ȡ�е�middle
		if(v<a[m]){
			return fd(l,m,v);
		}else{
			return fd(m,r,v);
		}
	}
}
