#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p,n;
    while(cin>>p>>n){
        int t[n],v[n],f[p+10];
        for(int i=0;i<n;i++){
            cin>>v[i]>>t[i];
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            for(int j=p;j>=t[i];j--){
                //cout<<"**"<<f[p-t[i]]+v[i]<<" "<<f[p]<<endl;
                f[j]=max(f[j-t[i]]+v[i],f[j]);
            }
        cout<<f[p]<<endl;
    }
}
