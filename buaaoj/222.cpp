/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 348603
 Created at: Sat Oct 28 2017 00:01:45 GMT+0800 (CST)
 Problem_id: 222	Time: 1	Memory: 2696
*/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int t;
char a[1000000],b[1000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        int la=0,lb=0,lm,ln;
        while(a[la]!='\0') la++;
        while(b[lb]!='\0') lb++;
        lm=max(la,lb);
        ln=min(la,lb);
        char na[lm],nb[lm],nc[lm];
        for(int p=1;p<=lm;p++){
            if(la-p<0){
                na[p-1]='0';
            }else{
                na[p-1]=a[la-p];
            }
            if(lb-p<0){
                nb[p-1]='0';
            }else{
                nb[p-1]=b[lb-p];
            }
        }
        int mat=0;
        for(int q=0;q<lm;q++){
            nc[q]=(na[q]+nb[q]-'0'-'0'+mat)%10+'0';
            if(na[q]+nb[q]+mat-'0'-'0'>9){
                mat=1;
            }else{
                mat=0;
            }
        }
        if(mat!=0){
            cout<<mat;
        }
        for(int v=lm-1;v>=0;v--){
            if((mat==0)&&(nc[v]=='0')){
                continue;
            }else{
                mat++;
            }
            cout<<nc[v];
        }
        cout<<endl;
    }

}
