#include<bits/stdc++.h>
using namespace std;
//No. of test case = 3;
// Input string -->
/* {[()]}
   {[(])}
   {{[[(())]]}} */
unordered_map<char,int> sy = { {'(',1}  ,{'{',2}  , {'[',3} , {')',-1}  ,{'}',-2}  , {']',-3} };
void check(string s){
    stack<char> st;
    // s = "{[()]}" ;
    for(char br : s){
        if(sy[br] > 0 ){
            st.push(br) ;
        }
        else{
            if(st.empty()){cout<<"No\n"; break;}
            // char take = st.top() ; 
            //take = '(' ;
            // if(sy[take] + sy[br] != 0){cout<<"No\n"; break;}
            if(sy[st.top()] + sy[br] != 0){cout<<"No\n"; break;}
            st.pop() ;
        }
    }
    if(st.empty()){cout<<"Yes\n";}
}
int main(){
    int t;
    cout<<"no. of test case : ";
    cin>>t;
    while(t--){
        string st;
        cout<<"enter the string : ";
        cin>> st;
        check(st) ;


    }
}