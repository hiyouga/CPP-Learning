#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double T;
    int k;
    while(cin>>T>>k){
        double t[k],v[k];
        for(int i=0;i<k;i++){
            cin>>v[i]>>t[i];
        }
        for(int p=0;p<k;p++){
            double mv=0,temp;
            int pos;
            for(int q=p;q<k;q++){
                temp=v[q]/t[q];
                if(temp>mv){
                    mv=temp;
                    pos=q;
                }
            }
            if(p!=pos){
                swap(v[p],v[pos]);
                swap(t[p],t[pos]);
            }
            //cout<<v[p]<<" "<<t[p]<<endl;
        }
        double s=0;
        for(int i=0;i<k;i++){
            if(T-t[i]>=0){
                s+=v[i];
                T-=t[i];
            }
        }
        cout<<s<<endl;
    }
}
