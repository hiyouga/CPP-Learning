/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 308159
 Created at: Thu Sep 07 2017 21:24:09 GMT+0800 (CST)
 Problem_id: 841	Time: 3	Memory: 1776
*/

#include<stdio.h>
#include<math.h>
int main(){
    float x1,y1,x2,y2,s;
    scanf("(%f, %f) (%f, %f)",&x1,&y1,&x2,&y2);
    s=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    printf("%.3fm",s);
}
