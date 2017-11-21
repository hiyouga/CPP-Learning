#include<iostream>
#include<cstdlib>
using namespace std;
double f[100][101];
void dump(int n)
{
    cout<<"The changed map is:"<<endl;
    for(int i=0;i<n;i++){
        for(int k=0;k<n+1;k++){
            cout<<f[i][k]<<ends;
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"输入未知数个数：";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int k=0;k<n+1;k++){
            cin>>f[i][k];
        }
    }
    for(int t=0;t<n;t++){
        if(f[t][t]==0){
            for(int d=t;d<n+1;d++){
                double temp = f[t][d];
                f[t][d] = f[t+1][d];
                f[t+1][d] = temp;
            }
        }
        for(int r=t+1;r<n;r++){
            double q = -f[r][t]/f[t][t];
            for(int d=t;d<n+1;d++){
                f[r][d] += q * f[t][d];
            }
        }
        dump(n);
    }
    double s,x[n];
    int d;
    cout<<"The answer is:"<<endl;
    for(int r=n-1;r>=0;r--){
        s=f[r][n];
        for(d=n-1;d>r;d--){
            s-=f[r][d]*x[d];
        }
        x[r] = s/f[r][d];
        //if(x[r]-int(x[r])==0){
            cout<<"x"<<r+1<<" = "<<x[r]<<endl;
        /*}else{
            cout<<"x"<<r+1<<" = "<<s<<"/"<<f[r][d]<<endl;
        }*/
    }
    system("pause");
    return 0;
}
