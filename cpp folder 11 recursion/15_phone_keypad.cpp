#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve(string digits,string op,int id,vector<string> &ans,vector<string> mapping){
    if(id >= digits.length()){ans.push_back(op); return ;}

    int n = digits[id] - '0';
    string value = mapping[n] ;

    for(int i = 0;i<value.length();i++){
        op.push_back(value[i]);
        solve(digits,op,id+1,ans,mapping);
        // op.pop_back();
    }
}

int main(){
    string st;
    cin>>st;
    vector<string> ans;
    string op ;
    int in = 0;
    vector<string> str = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(st,op,in,ans,str);

    for(auto i : ans){cout<<i<<" ";}
}