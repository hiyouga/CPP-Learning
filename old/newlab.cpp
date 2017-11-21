#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<sstream>
using namespace std;
string buffer[21];
string strb[56]={
    "A11",
    "A12",
    "A13",
    "A14",
    "A30",
    "A31",
    "A32",
    "A33",
    "A34",
    "A40",
    "A41",
    "A42",
    "A43",
    "A44",
    "A45",
    "A46",
    "A47",
    "A48",
    "A49",
    "A410",
    "A61",
    "A62",
    "A63",
    "A64",
    "A65",
    "A71",
    "A72",
    "A73",
    "A74",
    "A75",
    "A91",
    "A92",
    "A93",
    "A94",
    "A95",
    "A101",
    "A102",
    "A103",
    "A121",
    "A122",
    "A123",
    "A124",
    "A141",
    "A142",
    "A143",
    "A151",
    "A152",
    "A153",
    "A171",
    "A172",
    "A173",
    "A174",
    "A191",
    "A192",
    "A201",
    "A202"
};
string strn[56]={
    "3175",//A11
    "3830",//A12
    "2177",//A13
    "3133",//A14
    "743",//A30
    "1307",//A31
    "3686",//A32
    "1122",//A33
    "3841",//A34
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
    "3317",//A61
    "3698",//A62
    "3020",//A63
    "2542",//A64
    "3162",//A65
    "",//A71
    "",//A72
    "",//A73
    "",//A74
    "",//A75
    "",//A91
    "",//A92
    "",//A93
    "",//A94
    "",//A95
    "",//A101
    "",//A102
    "",//A103
    "",//A121
    "",//A122
    "",//A123
    "",//A124
    "",//A141
    "",//A142
    "",//A143
    "3378",//A151
    "3331",//A152
    "2708",//A153
    "2521",//A171
    "3354",//A172
    "3308",//A173
    "3119",//A174
    "",//A191
    "",//A192
    "",//A201
    ""//A202
};
int pass[15]={1,3,4,6,8,9,10,11,12,13,15,17,18,19,20};
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
            int flag=0;
            in>>buffer[i];
            for(int t=0;t<15;t++){
                if(i==pass[t]){
                    buffer[i]="";
                    flag=1;
                }
            }
            if(i==7){
                if(buffer[i]=="1")
                    buffer[i]="4321";
                if(buffer[i]=="2")
                    buffer[i]="4185";
                if(buffer[i]=="3")
                    buffer[i]="3313";
                if(buffer[i]=="4")
                    buffer[i]="2516";
            }
            if(!flag){
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
