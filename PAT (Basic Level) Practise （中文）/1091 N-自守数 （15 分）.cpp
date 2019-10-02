/*

1091 N-自守数 （15 分）

*/

#include<iostream>
#include<string>
using namespace std;

bool Judge(const string& s1,const string& s2){
    int len1=s1.size()-1,len2=s2.size()-1;
    for(;len1>=0&&len2>=0;len1--,len2--){
        if(s1[len1]!=s2[len2]){
            return false;
        }
    }
    return true;
}

int main()
{
    int N,a,b;
    string t1,t2;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        bool flag=false;
        for(int j=1;j<10;j++){
            b=j*a*a;
            t1=to_string(b);
            t2=to_string(a);
            if(Judge(t1,t2)){
                cout<<j<<" "<<t1<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<"No"<<endl;
    }

    return 0;
}
