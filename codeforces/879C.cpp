#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    char op;
    int x;
    int a=0,b=1023;
    for(int i=0;i<n;i++){
        cin>>op>>x;
        if(op=='&'){
            a&=x,b&=x;
        }else if(op=='|'){
            a|=x,b|=x;
        }else{
            a^=x,b^=x;
        }
    }
    cout<<3<<endl;
    cout<<"& "<<((1023&a)|b)<<endl;
    cout<<"^ "<<(a&(1023^b))<<endl;
    cout<<"| "<<(a&b)<<endl;
}
