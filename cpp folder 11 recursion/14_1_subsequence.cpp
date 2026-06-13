#include<iostream>
#include<string>
#include<vector>
using namespace std;

void subsequence(string st,int s,vector<string> &vs,string op){
    if(s >= st.length()){
        if(op.length()){vs.push_back(op);} return ;
    }

    // exclude
    subsequence(st,s+1,vs,op);

    // include
    char ch = st[s];
    op.push_back(ch);
    subsequence(st,s+1,vs,op);
}

void printvecofstring(vector<string> v){
    for(int i = 0; i< v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    string st = {"abc"};
    // cin>>st;
    vector<string> vs;
    string op;
    subsequence(st,0,vs,op);
    cout<<"{";
    printvecofstring(vs);
    cout<<"}";
}