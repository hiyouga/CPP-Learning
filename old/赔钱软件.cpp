#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand((unsigned)time(NULL));
    int a=rand()%10,b=5,d=500,c=0,e=0;
    cout<<"**********************************************\n��ӭ���������׼����϶ĳ�����Ů�ɹ����߷��ƣ�\n**********************************************\n";
	cout<<"Your money is:"<<d<<endl<<"use:";
	while(cin>>c){
        if(d<=0) break;
        if(c%100!=0){
            cout<<"���������Ϊ100�ı���"<<endl<<"use:";
            continue;
        }
        if(c>d){
            cout<<"��û����ô��Ǯ��"<<endl<<"use:";
            continue;
        }
        if(a>b){
            d+=c;
        }else{
            d-=c;
            if(d<=0){
                cout<<"���Ǯ�Ѿ������ˣ�"<<endl;
                cout<<"Game over"<<endl<<"��������"<<e<<"��"<<endl;
            }
        }
        e++;
        cout<<"Your money is:"<<d<<endl<<"use:";
        a=rand()%10;
	}
	return 0;
}

