#include<iostream>
using namespace std;
int main()
{
    int n;//1's
    long long x,s=0;//length
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    s+=n-1;
    if(s==x){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}
