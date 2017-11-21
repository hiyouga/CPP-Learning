#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand((unsigned)time(NULL));
    int a=rand()%10,b=5,d=500,c=0,e=0;
    cout<<"**********************************************\n欢迎来到澳门首家线上赌场，美女荷官在线发牌！\n**********************************************\n";
	cout<<"Your money is:"<<d<<endl<<"use:";
	while(cin>>c){
        if(d<=0) break;
        if(c%100!=0){
            cout<<"输入金额必须为100的倍数"<<endl<<"use:";
            continue;
        }
        if(c>d){
            cout<<"你没有这么多钱！"<<endl<<"use:";
            continue;
        }
        if(a>b){
            d+=c;
        }else{
            d-=c;
            if(d<=0){
                cout<<"你的钱已经花光了！"<<endl;
                cout<<"Game over"<<endl<<"您共撑了"<<e<<"轮"<<endl;
            }
        }
        e++;
        cout<<"Your money is:"<<d<<endl<<"use:";
        a=rand()%10;
	}
	return 0;
}

