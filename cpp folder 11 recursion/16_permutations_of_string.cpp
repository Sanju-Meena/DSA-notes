#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void permutations(string st,int id,vector<string> &v){
    if(id >= st.length()){v.push_back(st); return;}

    for(int i = id ;i < st.length();i++){
        swap(st[id],st[i]);
        cout<<st<<endl;
        permutations(st,id+1,v);
        swap(st[id],st[i]);
    }
}

int main(){
    string st;
    // cin>>st;
    st = {"abc"};
    vector<string> vs;
    permutations(st,0,vs);
    sort(vs.begin(),vs.end());
    cout<<endl;
    for(auto i : vs){cout<<i<<" ";}
}