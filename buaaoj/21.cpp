/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323264
 Created at: Thu Oct 19 2017 10:42:31 GMT+0800 (CST)
 Problem_id: 21	Time: 1	Memory: 2612
*/

#include<iostream>
using namespace std;
int main()
{
    int x;
    while(cin>>x){
        if(x<0||x>100){
            cout<<"wrong";
        }else if(x<60){
            cout<<'E';
        }else if(x<70){
            cout<<'D';
        }else if(x<80){
            cout<<'C';
        }else if(x<90){
            cout<<'B';
        }else{
            cout<<'A';
        }
        cout<<endl;
    }
}
