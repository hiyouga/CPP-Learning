/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 308213
 Created at: Fri Sep 08 2017 01:17:52 GMT+0800 (CST)
 Problem_id: 840	Time: 3	Memory: 2604
*/

#include<iostream>
int main()
{
    using namespace std;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        long long a[x],f;
        for(int p=0;p<x;p++){
            cin >> a[p];
        }
        cin >> f;
        for(int q=0;q<x;q++){
            int max_at=q;
            for(int r=q;r<x;r++){
                max_at=a[r]>a[max_at]?r:max_at;
            }
            if(max_at!=q){
                long long temp=a[q];
                a[q]=a[max_at];
                a[max_at]=temp;
            }
        }
        unsigned long long s=0;
        for(int u=0;u<3;u++){
            s=(s%f+a[u]%f)%f;
        }
        cout << s << endl << endl;
    }
}
