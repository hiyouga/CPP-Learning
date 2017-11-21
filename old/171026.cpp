#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    double a[3],b[3],c[3],d[3];
    cout<<fixed<<setprecision(2);
    while(cin>>a[0]>>b[0]>>c[0]>>a[1]>>b[1]>>c[1]>>a[2]>>b[2]>>c[2]){
        d[0] = a[0]*b[1]-a[1]*b[0];
        cout<<(b[0]*c[1]-b[1]*c[0])/d[0]<<(a[1]*c[0]-a[0]*c[1])/d[0]<<endl;
        d[1] = a[0]*b[2]-a[2]*b[0];
        cout<<(b[0]*c[2]-b[2]*c[0])/d[1]<<(a[2]*c[0]-a[0]*c[2])/d[1]<<endl;
        d[2] = a[2]*b[1]-a[1]*b[2];
        cout<<(b[2]*c[1]-b[1]*c[2])/d[2]<<(a[1]*c[2]-a[2]*c[1])/d[2]<<endl;
    }
}
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    double a[3],b[3],c[3],d[3],x[3],y[3];
    cout<<fixed<<setprecision(2);
    while(cin>>a[0]>>b[0]>>c[0]>>a[1]>>b[1]>>c[1]>>a[2]>>b[2]>>c[2]){
        int k=0;
        d[0] = a[0]*b[1]-a[1]*b[0];
        if(d[0]!=0){
            x[k]=(b[0]*c[1]-b[1]*c[0])/d[0];
            y[k]=(a[1]*c[0]-a[0]*c[1])/d[0];
            k++;
        }
        d[1] = a[0]*b[2]-a[2]*b[0];
        if(d[1]!=0){
            x[k]=(b[0]*c[2]-b[2]*c[0])/d[1];
            y[k]=(a[2]*c[0]-a[0]*c[2])/d[1];
            k++;
        }
        d[2] = a[2]*b[1]-a[1]*b[2];
        if(d[2]!=0){
            x[k]=(b[1]*c[2]-b[2]*c[1])/d[2];
            y[k]=(a[2]*c[1]-a[1]*c[2])/d[2];
            k++;
        }
        cout<<k<<endl;
        for(int i=0;i<k;i++){
            cout<<x[i]<<" "<<y[i]<<endl;
        }
    }
}
