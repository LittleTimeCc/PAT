/*
1095 解码PAT准考证 （25 分）

*/

#include<iostream>
#include<string>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    string s;
    int value;
};

int main(){
    int n,m,t;
    string s;
    cin>>n>>m;
    vector<Node> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].s>>v[i].value;
    }
    for(int i=1;i<=m;i++){
        cin>>t>>s;
        printf("Case %d: %d %s\n",i,t,s.c_str());
        vector<Node> ans;
        int cnt=0,sum=0;
        if(t==1){
            for(const auto& elem:v){
                if(elem.s[0]==s[0]){
                    ans.push_back(elem);
                }
            }
        }else if(t==2){
            for(const auto& elem:v){
                if(elem.s.substr(1,3)==s){
                   cnt++;
                   sum+=elem.value;
                }
            }
            if(cnt){printf("%d %d\n",cnt,sum);} 
        }else if(t==3){
            unordered_map<string,int> m;
            for(const auto& elem:v){
                if(elem.s.substr(4,6)==s){
                    m[elem.s.substr(1,3)]++;
                }
            }
            for(const auto& elem:m){
                ans.push_back({elem.first,elem.second});
            }
        }
        sort(ans.begin(),ans.end(),[](const Node& lhs,const Node& rhs){
            return lhs.value!=rhs.value?lhs.value>rhs.value:lhs.s<rhs.s;
        });
        for(const auto& elem:ans){
            printf("%s %d\n",elem.s.c_str(),elem.value);
        }
        if(((t==1||t==3)&&ans.empty())||(t==2&&cnt==0)){
            printf("NA\n");
        }
    }



    return 0;
}