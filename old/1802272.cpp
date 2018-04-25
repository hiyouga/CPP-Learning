#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    int n, in, t = 0, s = 0, k = 0;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> in >> str;
        while(k < in){
        	if(t > 0){
        		s += 2;
        		t--;
        	}else{
        		s += 1;
        	}
        	k++;
        }
        if(str == "in"){
        	t += 5;
        }else{
        	t += 3;
        }
    }
    while(k < 24){
		if(t > 0){
			s += 2;
			t--;
		}else{
			s += 1;
		}
		k++;
	}
	cout << s << endl;
    return 0;
}