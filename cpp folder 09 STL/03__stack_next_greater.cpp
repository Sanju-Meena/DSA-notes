#include<bits/stdc++.h>
using namespace std;
// find next greater element array;
// having TC = O(n) ;
int main(){
    vector<int> v = {4,5,2,25,7,8};
    vector<int> p ;
    stack<int> st;
    int s = v.size() ;
    for(int i =0;i<s;i++){
        if(p.size() == 0){st.push(v[i]);}
        else{
            if(v[i]>st.top()){ st.pop(); st.push(v[i]);}
        }
    }
}