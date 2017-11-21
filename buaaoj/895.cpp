/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 369795
 Created at: Thu Nov 02 2017 11:10:00 GMT+0800 (CST)
 Problem_id: 895	Time: 7	Memory: 2736
*/

#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int good,grd[2][3];double gpa;
    cin>>good>>gpa>>grd[0][0]>>grd[0][1]>>grd[0][2]>>grd[1][0]>>grd[1][1]>>grd[1][2];
    double ave[2];
    ave[0]=(grd[0][0]+grd[0][1]+grd[0][2])/3.0;
    ave[1]=(grd[1][0]+grd[1][1]+grd[1][2])/3.0;
    if(good==1){
        if(gpa>=3.5||(ave[0]>=80&&ave[1]>=80)){
            cout<<"APPROVED"<<endl;
        }else{
            cout<<"REJECTED"<<endl;
        }
    }else{
        if(gpa>=3.6||(ave[0]>85&&ave[1]>85)){
            cout<<"APPROVED"<<endl;
        }else{
            cout<<"REJECTED"<<endl;
        }
    }
}
