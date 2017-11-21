#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        int x[n],r[n],s=0;
        for(int i=0;i<n;i++){
            cin>>x[i]>>r[i];
        }
        for(int p=0;p<n;p++){
            if(abs(x[p]-x[q])>r[p]+r[q]) s++;
        }
        cout<<s<<endl;
    }
}
