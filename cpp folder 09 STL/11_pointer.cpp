#include<bits/stdc++.h>
using namespace std;
//  2,3,0 5 0 3 ------> 2 3 5 3 0 0.
int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);
    }

    for(int i = 0,j = 0;i<n;i++){
        if(v[i]!=0){swap(v[j],v[i]);j++;}
    }
    for(auto it : v){cout<<it<<" ";} cout<<endl;
}