#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int n[3][2],s[3],max_s=0,pos;
    for(int p=0;p<3;p++){
        for(int q=0;q<2;q++){
            cin>>n[p][q];
        }
        s[p]=n[p][0]*n[p][1];
        if(s[p]>max_s){
            max_s=s[p];
            pos=p;
        }
    }
    swap(n[pos][0],n[0][0]);
    swap(n[pos][1],n[0][1]);
    if(n[0][0]>=(n[1][0]+n[2][0])&&n[0][1]>=max(n[1][1],n[2][1])){
        cout<<"SIXSIXSIX!"<<endl;
    }else if(n[0][0]>=(n[1][0]+n[2][1])&&n[0][1]>=max(n[1][1],n[2][0])){
        cout<<"SIXSIXSIX!"<<endl;
    }else if(n[0][0]>=(n[1][1]+n[2][0])&&n[0][1]>=max(n[1][0],n[2][1])){
        cout<<"SIXSIXSIX!"<<endl;
    }else if(n[0][0]>=(n[1][1]+n[2][1])&&n[0][1]>=max(n[1][0],n[2][0])){
        cout<<"SIXSIXSIX!"<<endl;
    }else{
        cout<<"GG!"<<endl;
    }

}
