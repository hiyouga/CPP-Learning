/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 315722
 Created at: Thu Oct 12 2017 11:24:29 GMT+0800 (CST)
 Problem_id: 9	Time: 53	Memory: 2688
*/

#include<iostream>
using namespace std;
void mov(int n,char a,char b,char c){
    if(n==1){
        cout<<a<<" to "<<c<<endl;
    }else{
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
