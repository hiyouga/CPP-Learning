#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main()
{
	int n;
	string glt, raw;
	cin >> glt >> raw >> n;
	set<char> goods;
	bool has = (raw.find('*') != string::npos) ? true : false;
	for(int i = 0; i < glt.length(); i++){
		goods.insert(glt[i]);
	}
	/*for(set<char>::iterator ite = goods.begin(); ite != goods.end(); ite++){
		cout << *ite << endl;
	}*/
	for(int t = 0; t < n; t++){
		string qst;
		cin >> qst;
		bool cor = true;
		int p = 0;
		int bgp = 0, edp = qst.length() - 1;
		for(int i = 0; i < raw.length(); i++){
			if(raw[i] == qst[p]){
				p++;
			}else if(raw[i] == '?' && goods.count(qst[p])){
				p++;
			}else if(raw[i] == '*'){
				break;
			}else{
				cor = false;
				break;
			}
		}
		bgp = p;
		p = qst.length() - 1;
		for(int i = raw.length() - 1; i >= 0; i--){
			if(raw[i] == qst[p]){
				p--;
			}else if(raw[i] == '?' && goods.count(qst[p])){
				p--;
			}else if(raw[i] == '*'){
				break;
			}else{
				cor = false;
				break;
			}
		}
		edp = p;
		//cout << bgp << " " << edp << endl;
		for(int i = bgp; i <= edp; i++){
			if(goods.count(qst[i])){
				cor = false;
			}
		}
		if(raw.length() - has > qst.length() || (!has && qst.length() > raw.length())){
			cor = false;
		}
		if(!cor){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	return 0;
}