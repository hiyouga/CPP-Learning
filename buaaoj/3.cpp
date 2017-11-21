#include<iostream>
int main(){
    using namespace std;
    int n,m,k;
    long s;
    while(cin>>n>>m>>k){
        s=0;
        for(int i=0;i<=k;i++){
            s+=n;
            n+=m;
        }
        cout<<s<<endl;
    }
}
