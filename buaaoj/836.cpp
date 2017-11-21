/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 308221
 Created at: Fri Sep 08 2017 02:33:51 GMT+0800 (CST)
 Problem_id: 836	Time: 3	Memory: 2660
*/

#include<iostream>
#include<cstring>
int func(std::string);
int main()
{
    using namespace std;
    string str;
    while(getline(cin,str)){
            int flag=0;
            int pos = str.find(" ");
            int rpos = str.rfind(" ");
            const char * y = str.substr(0,pos).c_str();
            for(int p=0;p<4;p++){
                if(y[p]<'0'||y[p]>'9'){
                    flag+=1;break;
                }
            }
            flag+=func(str.substr(pos+1,rpos-pos-1));
            flag+=func(str.substr(rpos+1));
            if(!!flag){
                cout<<"qiu qiu ni le, gai ming pian ba"<<endl;
            }else{
                cout<<"meng xin bao zhao!"<<endl;
            }
    }
}
int func(std::string str){
    int flag=0;
    const char * m=str.c_str();
    for(int q=0;q<str.length();q++){
        if(m[q]<'A'||(m[q]>'Z'&&m[q]<'a')||m[q]>'z'){
            flag=1;break;
        }
    }
    return flag;
}
