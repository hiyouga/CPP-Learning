#include<iostream>
using namespace std;
void mov(int n,char a,char b,char c){
    if(n>=1){
        mov(n-1,a,c,b);
        cout<<a<<" to "<<c<<endl;
        mov(n-1,b,a,c);
    }
}
int main()
{
    int n;
    while(cin>>n){
        mov(n,'A','B','C');
        cout<<endl;
    }
}
