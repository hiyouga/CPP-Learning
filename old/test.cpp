#include<iostream>
int main()
{
    using namespace std;
    int x,flag=0;
    cin>>x;
    for(int i=2;i<=x;i++){
        flag=0;
        if(x%i==0){
            for(int p=2;p<i;p++){
                if(i%p==0)flag++;
            }
            if(flag==0)cout<<i<<endl;
        }
    }
    return x;
}
