//http://blog.csdn.net/shizhengtong0829/article/details/50422879
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,k;
    while(cin>>T>>k){
        int t[k],v[k],f[T+10];
        for(int i=0;i<k;i++){
            cin>>v[i]>>t[i];
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<k;i++)
            for(int p=T;p>=t[i];p--){
                //cout<<"**"<<f[p-t[i]]+v[i]<<" "<<f[p]<<endl;
                f[p]=max(f[p-t[i]]+v[i],f[p]);
            }
        cout<<f[T]<<endl;
    }
}
