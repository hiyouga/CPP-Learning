#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
string buffer[21];
int main()
{
    ifstream in("german.data");
    ofstream out("german.data-ave");
    if(!in.is_open()){
        cout<<"Error opening file";exit(1);
    }
    while(!in.eof()){
        for(int i=0;i<21;i++){
            in>>buffer[i];
            buffer[i]=change(buffer[i]);
            out<<buffer[i];
            if(i!=20) out<<" ";
        }
        out<<endl;
    }
    cout<<"Completed!"<<endl;
    system("pause");
    return 0;
}

