#include<bits/stdc++.h>
using namespace std;
int n,a[23],b[23],c[23],nb,nc,topb,topc;
long long pb[2001000],pc[2001000];
long long k;
void calcb(long long num,int now)
{
	if (now>nb) {pb[++topb]=num;return;}
	while (1)
	{
		calcb(num,now+1);
		if ((double)num*b[now]>1.1e18) break;
		num*=b[now];
	}
}
void calcc(long long num,int now)
{
	if (now>nc) {pc[++topc]=num;return;}
	while (1)
	{
		calcc(num,now+1);
		if ((double)num*c[now]>1.1e18) break;
		num*=c[now];
	}
}
long long calc(long long lim)
{
	long long ans=0;
	long long *d=pb+topb+1;
	for (int i=1;i<=topc;i++)
	{
		if (pc[i]>lim) break;
		d=upper_bound(pb+1,d,lim/pc[i]);
		ans+=d-(pb+1);
	}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%lld",&k);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i+=2) b[++nb]=a[i];
	for (int i=2;i<=n;i+=2) c[++nc]=a[i];
	calcb(1,1);calcc(1,1);
	sort(pb+1,pb+topb+1);sort(pc+1,pc+topc+1);
	long long l=0,r=2e18;
	while (l+1!=r)
	{
		long long mid=(l+r)>>1;//cerr<<mid<<' '<<calc(mid)<<endl;
		if (calc(mid)<k) l=mid;else r=mid;
	}
	cout<<r<<endl;
}
