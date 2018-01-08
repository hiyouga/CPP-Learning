#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
const ll N = 100005;

ll n, m, x, y, z, cnt, ans;
ll a[N], b[N];

vector<pair<ll,ll> > st[N], ch;

void proc (ll M, ll R, ll H, ll S, ll E) {
	if(H > z) return;
	ch.push_back({S, 1});
	if(R == 0 || M <= z) {
		if(~E) ch.push_back({E, -1});
	}
	else {
		ll req = (z+1 - H + R-1) / R;
		if(~E) ch.push_back({min(E, S+req), -1});
		else ch.push_back({S+req, -1});
	}
}

int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&m,&x,&y,&z);
	for(ll i=1;i<=n;i++) {
		ll T;
		scanf("%lld%lld%lld",&a[i],&T,&b[i]);
		st[i].push_back({0, T});
	}
	for(ll i=1;i<=m;i++) {
		ll A, B, C;
		scanf("%lld%lld%lld",&A,&B,&C);
		st[B].push_back({A, C});
	}
	for(ll i=1;i<=n;i++) {
		sort(st[i].begin(), st[i].end());
		for(ll j=0;j<st[i].size();j++) {
			proc(a[i], b[i], st[i][j].Y, st[i][j].X, (j+1 == st[i].size() ? -1 : st[i][j+1].X));
		}
	}
	sort(ch.begin(), ch.end());
	for(ll i=0;i<ch.size();i++) {
		cnt += ch[i].Y;
		if(i+1 != ch.size() && ch[i].X != ch[i+1].X) {
			ans = max(ans, cnt*(x+(ch[i+1].X-1)*y));
		}
	}
	if(cnt > 0) {
		if(y > 0) {puts("-1"); return 0;}
		else ans = max(ans, cnt*x);
	}
	printf("%lld\n",ans);
}
