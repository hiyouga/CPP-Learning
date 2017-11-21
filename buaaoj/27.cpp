/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323590
 Created at: Thu Oct 19 2017 19:58:47 GMT+0800 (CST)
 Problem_id: 27	Time: 1	Memory: 2524
*/

#include<iostream>
using namespace std;
int main()
{
    long n;
    while(cin>>n){
        int i=0;
        while(n!=1){
            if(n%2==0){
                n/=2;
                i++;
            }else{
                n=3*n+1;
                i++;
            }
        }
        cout<<i<<endl;
    }
}
