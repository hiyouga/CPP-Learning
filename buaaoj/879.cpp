/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 336357
 Created at: Mon Oct 23 2017 19:56:58 GMT+0800 (CST)
 Problem_id: 879	Time: 3	Memory: 2580
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<sstream>
using namespace std;
int main()
{
    char n[1000000];
    cin>>n;
    stringstream stream;
    int x=0;
    stream<<n;
    stream>>x;
    if(x==0){
        cout<<x;
    }else{

    int i=0;
    while(n[i]!='\0'){
        i++;
    }
    if(i<4){
        for(int q=i-1;q>=0;q--){
            cout<<n[q];
        }
        for(int p=0;p<4-i;p++){
            cout<<"0";
        }
        cout<<endl;
    }else{
        for(int p=0;p<i-4;p++){
            cout<<n[p];
        }
        for(int q=i-1;q>i-5;q--){
            cout<<n[q];
        }
        cout<<endl;
    }
    }
}
