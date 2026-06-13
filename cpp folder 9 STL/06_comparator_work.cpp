#include<bits/stdc++.h>
using namespace std;
// inbuilt sorting increasing order mai hoti hai.
// but hum comparator function khud banakr sort function ko de sakte hai but function joo hum banayange vo,
 //  true ko false accept karega or false ko true accept karega bcz ye bolta hai ki sort karna hai too false return karo.
bool s_i_s(int a,int b){
    if(a>b){return false;}
    return true;
}
bool cmp(pair<int,int> a , pair<int,int> b){
    if(a.first != b.first){
       if(a < b){return false;}
       return true;
    }
    else{
        if(a.second < b.second)return false;
        return true;
    }  
}

int main(){
    vector<int> v = {6,4,5,2,25,7,8} ;
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<pair<int,int>> p = {{4,3},{5,5},{5,3},{25,6},{8,5}} ;
    // sort(p.begin(),p.end()) ;
    // for(int i = 0;i<p.size();i++){
    //     cout<<p[i].first<<" "<<p[i].second<<endl;
    // }
    // cout<<endl;
    
    sort(p.begin(),p.end(),cmp) ;
    for(int i = 0;i<p.size();i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    
}