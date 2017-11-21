#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void sw(int &a,int &b)
{
    a^=b;
    b^=a;
    a^=b;
}
int main()
{
    int n;
    cin>>n;
    unsigned long long k,s[n];
    cin>>k;
    int a[n];
    memset(s,0,sizeof(s));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int p=0;
    if(k>n){
        int max_p=0;
        for(int y=0;y<n;y++){
            max_p=max(max_p,a[y]);
        }
        cout<<max_p;
    }else{
    while(true){
        if(p==n-1){
            if(a[p]>a[0]){
                s[p]++;
                if(s[p]==k)break;
                swap(a[p],a[0]);
                swap(s[p],s[0]);
            }else{
                s[0]++;
                if(s[0]==k)break;
            }
            p=0;
        }else{
            if(a[p]>a[p+1]){
                s[p]++;
                if(s[p]==k)break;
                swap(a[p],a[p+1]);
                swap(s[p],s[p+1]);
            }else{
                s[p+1]++;
                if(s[p+1]==k)break;
            }
            p++;
        }
    }
    cout<<a[p];
    }
}
