#include<iostream>
#include<cstring>
using namespace std;
int judge(int a,int b){
    if(a<b){
        a^=b;
        b^=a;
        a^=b;//Swap a and b
    }
    if(b==0)
        return 0;
    for(int i=a/b;i>0;i--)
        if(judge(a-b*i,b)==0)
            return 1;
    return 0;
}
int main()
{
    int a,b;
    while(cin>>a>>b){
        string s;
        s=judge(a,b)?"Nova":"LaoWang";
        cout<<s<<endl;
    }
}
