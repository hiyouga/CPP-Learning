/*
 * data_convert.cpp by hoshi_hiyouga
 * last_modified in 2017/11/06 19:37
 * Convert the characters to numbers
 * Only for BUAA MCM Qualification Competition
 */
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<sstream>
using namespace std;
string buffer[21];
string strb[56]={"A11","A12","A13","A14","A30","A31","A32","A33","A34","A40","A41","A42","A43","A44","A45","A46","A47","A48","A49","A410","A61","A62","A63","A64","A65","A71","A72","A73","A74","A75","A91","A92","A93","A94","A95","A101","A102","A103","A121","A122","A123","A124","A141","A142","A143","A151","A152","A153","A171","A172","A173","A174","A191","A192","A201","A202"};
string strn[56]={
    "1",//A11
    "2",//A12
    "3",//A13
    "4",//A14
    "0",//A30
    "1",//A31
    "2",//A32
    "3",//A33
    "4",//A34
    "",//A40
    "",//A41
    "",//A42
    "",//A43
    "",//A44
    "",//A45
    "",//A46
    "",//A47
    "",//A48
    "",//A49
    "",//A410
    "1",//A61
    "2",//A62
    "3",//A63
    "4",//A64
    "5",//A65
    "1",//A71
    "2",//A72
    "3",//A73
    "4",//A74
    "5",//A75
    "1",//A91
    "2",//A92
    "3",//A93
    "4",//A94
    "5",//A95
    "",//A101
    "",//A102
    "",//A103
    "1",//A121
    "2",//A122
    "3",//A123
    "4",//A124
    "1",//A141
    "2",//A142
    "3",//A143
    "1",//A151
    "2",//A152
    "3",//A153
    "1",//A171
    "2",//A172
    "3",//A173
    "4",//A174
    "",//A191
    "",//A192
    "",//A201
    ""//A202
};
string change(string temp)
{
    for(int k=0;k<56;k++){
        if(temp==strb[k]) temp=strn[k];
    }
    return temp;
}
int main()
{
    ifstream in("german.data");
    ofstream out("german.data-numeric");
    if(!in.is_open()){
        cout<<"Error opening file";exit(1);
    }
    while(!in.eof()){
        for(int i=0;i<21;i++){
            in>>buffer[i];
            if(i==12){
                stringstream stream;
                int age;
                stream<<buffer[i];
                stream>>age;
                if(age<30){
                    buffer[i]="1";
                }else if(age>50){
                    buffer[i]="3";
                }else{
                    buffer[i]="2";
                }
            }else{
                buffer[i]=change(buffer[i]);
            }
            out<<buffer[i];
            if(i!=20) out<<" ";
        }
        out<<endl;
    }
    cout<<"Completed!"<<endl;
    system("pause");
    return 0;
}
