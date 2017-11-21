#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node {
    int e,nxt;
}node[200005],color[100005];
int n,f,num,cnum,ans,sd,h[100005],g[100005],a[100005],b[100005],c[100005];
bool vis[100005];
void add(int s,int e){
    node[++num].e=e;
    node[num].nxt=h[s];
    h[s]=num;
}
void add_color(int s,int e){
	color[++cnum].e=e;//
	color[cnum].nxt=g[s];
	g[s]=cnum;
}
int fd(int l,int r,int v){//v��Ҫ�ҵ����֣�l����߽磬r���ұ߽�
	if(l+1 == r){
		return l;//�����+1=�ҽ磬���������±�
	}else{
		int m = (l+r)/2;//ȡ�е�middle
		if(v<a[m]){
			return fd(l,m,v);
		}else{
			return fd(m,r,v);
		}
	}
}
int dfs(int u,int pre){
    int i=h[u],d,fir=0,sec=0;
    vis[u]=true;
    while(i) {
        if(node[i].e!=pre) {
            d=dfs(node[i].e,u)+1;
            if(d>fir)
                sec=fir,fir=d;
            else if(d>sec)
                sec=d;
        }
        i=node[i].nxt;
    }
    ans=max(ans,fir+sec);
    return fir;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;//��������
    for(int i=0;i<t;i++){
        memset(vis,0,sizeof(vis));
        memset(h,0,sizeof(h));
        memset(g,0,sizeof(g));
        int n;
        cin>>n;//�����Ӧ���0~n-1�ڵ����ɫ
        for(int p=0;p<n;p++){
            cin>>a[p];
            c[p]=a[p];//����a������ a:0~n-1��n������
        }
        for(int q=0;q<n-1;q++){
            cin>>x>>y;//��x���ڵ�͵�y���ڵ�����
            if(c[x-1]==c[y-1]){
                add(x,y);
                add(y,x);
            }
        }
        sort(a,a+n);//��a����
        int l=unique(a,a+n)-a;//����ȥ�غ�a����ĳ��ȣ�l����ɫ��
        for(int s=0;s<n;s++){
            f = fd(0,l,c[s]);//�ҵ�����ɫ����ɫ����е�λ��
            add_color(f,s);
        }
        cout<<"Case "<<i+1<<":"<<endl;
        for(int z=0;z<l;z++){
            ans=num=cnum=0;
            for(int w=g[z];w;w=color[w].nxt){
                if(c[w]==a[z]){
                    sd=w+1;
                    if(!vis[w]){
                        dfs(sd,0);
                    }
                }
            }
            cout<<"color "<<a[z]<<":"<<ans+1<<endl;
        }
        cout<<endl;
    }
}
