/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 389140
 Created at: Thu Nov 09 2017 11:27:13 GMT+0800 (CST)
 Problem_id: 911	Time: 7	Memory: 2956
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int num_2,num_5;
long long pl(int n)
{
    if(n==0||n==1) return 1;
    int temp=n;
    while(temp%2==0){
        num_2++;
        temp/=2;
    }
    while(temp%5==0){
        num_5++;
        temp/=5;
    }
    return temp*pl(n-1)%(long long)pow(10,10);
}
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        num_2=0,num_5=0;
        cin>>n;
        long long s=pl(n);
        for(int i=0;i<num_2-num_5;i++){
            s=s*2%(long long)pow(10,10);
        }
        //cout<<num_2<<" "<<num_5<<endl;
        printf("%010lld\n",s);
        t--;
    }
}
