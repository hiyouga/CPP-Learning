#include <iostream>
#include <cctype>
#include <cstring>
#include <sstream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

string i2s(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int s2i(string s)
{
    int n;
    stringstream ss(s);
    ss >> n;
    return n;
}

int main()
{
    NOTLE
    int flag = 0, n, con = 1;
    char temp = '\0';
    string str, nst, num;
    cin >> n >> str;
    if(n == 1){
        for(int i = 0; i < str.length(); i++){
            if(temp == str[i]){
                flag = 1;
                con++;
            }else{
                if(flag){
                    nst += i2s(con);
                }
                flag = 0;
                con = 1;
                temp = str[i];
                nst += temp;
            }
        }
        if(flag){
            nst += i2s(con);
        }
    }else{
        for(int i = 0; i < str.length(); i++){
            if(isdigit(str[i])){
                while(isdigit(str[i])){
                    num += str[i];
                    i++;
                }
                for(int j = 1; j < s2i(num); j++){
                    nst += temp;
                }
                num = "";
                i--;
            }else{
                temp = str[i];
                nst += temp;
            }
        }
    }
    cout << nst << endl;
}
