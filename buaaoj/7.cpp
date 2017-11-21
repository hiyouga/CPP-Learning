/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 315718
 Created at: Thu Oct 12 2017 11:10:29 GMT+0800 (CST)
 Problem_id: 7	Time: 2	Memory: 2712
*/

#include<iostream>
using namespace std;
int main()
{
    int num;
    while(cin >> num){
        for(int i=num;i>0;i--){
            for(int p=0;p<num-i;p++){
                cout<<" ";
            }
            for(int t=0;t<i*2-1;t++){
                cout<<"#";
            }
            cout<<endl;
        }
    }
}
