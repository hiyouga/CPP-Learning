#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string n;
    cin>>n;
    int a=0,b=0;
    for(int i=0,flag=0;n[i]!='\0';i++){
        if(n[i]=='1'){
            a++;
            flag++;
        }else if(flag){
            b++;
        }else{
            continue;
        }
    }
    if(a>=1&&b>=6){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
}
