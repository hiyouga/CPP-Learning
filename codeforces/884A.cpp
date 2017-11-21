#include<iostream>
using namespace std;
int main()
{
    int n;
    long t;
    cin>>n>>t;
    int a[n];
    for(int p=0;p<n;p++){
        cin>>a[p];
    }
    int i=0;
    while(t>0){
        t-=86400-a[i];
        i++;
    }
    cout<<i<<endl;
}
