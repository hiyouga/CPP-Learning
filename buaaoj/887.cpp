/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 341304
 Created at: Wed Oct 25 2017 18:04:46 GMT+0800 (CST)
 Problem_id: 887	Time: 9	Memory: 2628
*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n[5];
    for(int i=0;i<5;i++){
        cin>>n[i];
    }
    if((n[0]<n[1])&&(n[1]<n[2])&&(n[2]>n[3])&&(n[3]>n[4])){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}
