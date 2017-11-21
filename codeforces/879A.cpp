#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s[n],d[n];
    for(int i=0;i<n;i++){
        cin>>s[i]>>d[i];
    }
    int t=0,p=0;
    while(p<n){
        int k=0;
        while(true){
            if(t<s[p]+k*d[p]){
                t=s[p]+k*d[p];
                break;
            }
            k++;
        }
        p++;
    }
    cout<<t;
}
