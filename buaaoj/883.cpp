/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 339939
 Created at: Tue Oct 24 2017 23:23:33 GMT+0800 (CST)
 Problem_id: 883	Time: 66	Memory: 2712
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct info{
    string name;
    unsigned int score;
};
info player[1005];
info * temp, * ranked[1005];
int n,check,c_rank,t=1,flag;

void change(int j,int k)
{
    for(int u=j;u<k;u++){
        temp=ranked[k];
        ranked[k]=ranked[u];
        ranked[u]=temp;
    }
}
int cmp(string a,string b)
{
    int l=min(a.length(),b.length());
    for(int k=0;k<l;k++){
        if(a[k]==b[k]){
            continue;
        }else if(a[k]>b[k]){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}
void dump()
{
    for(int w=1;w<=t;w++){
        cout<<ranked[w]->name<<ranked[w]->score<<endl;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>check;
        if(check==1){
            flag=0;
            cin>>player[t].name>>player[t].score;
            ranked[t] = &player[t];
            for(int e=1;e<t;e++){
                if(ranked[t]->name.compare(ranked[e]->name)==0){
                    ranked[e]->score=ranked[t]->score;
                    for(int p=1;p<e;p++){
                        if(ranked[p]->score>ranked[e]->score){
                            continue;
                        }else if(ranked[p]->score==ranked[e]->score){
                            if(cmp(ranked[p]->name,ranked[e]->name)){
                                change(p,e);
                            }else{
                                continue;
                            }
                        }else{
                            change(p,e);
                        }
                    }
                    for(int p=1;p<t-1;p++){
                        if(ranked[p]->score>ranked[p+1]->score){
                            continue;
                        }else if(ranked[p]->score==ranked[p+1]->score){
                            if(cmp(ranked[p]->name,ranked[p+1]->name)){
                                temp=ranked[p];
                                ranked[p]=ranked[p+1];
                                ranked[p+1]=temp;
                            }else{
                                continue;
                            }
                        }else{
                            temp=ranked[p];
                            ranked[p]=ranked[p+1];
                            ranked[p+1]=temp;
                        }
                    }
                    flag=1;
                }
            }
            if(flag==1){
                //dump();
                continue;
            }else{
                for(int p=1;p<t;p++){
                    if(ranked[p]->score>ranked[t]->score){
                        continue;
                    }else if(ranked[p]->score==ranked[t]->score){
                        if(cmp(ranked[p]->name,ranked[t]->name)){
                            change(p,t);
                        }else{
                            continue;
                        }
                    }else{
                        change(p,t);
                    }
                }
                //dump();
                t++;
            }
        }else{
            cin>>c_rank;
            cout<<ranked[c_rank]->name<<" "<<ranked[c_rank]->score<<endl;
        }
    }
}
