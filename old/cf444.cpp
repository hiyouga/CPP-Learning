#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n,f=0;
    cin>>n;
    int t,c[10],z[n];
    memset(c,0,sizeof(c));
    memset(z,0,sizeof(z));
    for(int i=0;i<n;i++){
        for(int k=0;k<6;k++){
            cin>>t;
            if(t<2){
                if(z[i]==0){
                    z[i]=1;
                }else{
                    f++;
                }
            }

            c[t]++;
        }
    }
    int num,s;
    for(int r=1,flag=0;!flag;r++){
        for(int p=0;p<10;p++){
            if((p==0&&c[p]<r-1)||(p!=0&&c[p]<r)){
                flag=1;
                num=p;
                s=r;
                break;
            }
        }
    }
    if(num==1&&f){
        int d=0;
        for(int q=0;q<s;q++){
            d+=num*pow(10,q);
        }
        cout<<d-2<<endl;
    }else{
        int d=0;
        for(int q=0;q<s;q++){
            d+=num*pow(10,q);
        }
        cout<<d-1<<endl;
    }

}
