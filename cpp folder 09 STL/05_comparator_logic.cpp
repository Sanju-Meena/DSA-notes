#include<bits/stdc++.h>
using namespace std;
// inbuilt conparator function hame sorting increasing order mai deta hai.
// but hum comparator function khud banakr sort function ko de sakte hai.
bool s_i_s(int a,int b){
    if(a>b){return true;}
    return false;
}
bool sh_i_s(pair<int,int> a , pair<int,int> b){
    if(a.first != b.first){
       if(a > b){return true;}
       return false;
    }
    else{
        if(a.second < b.second)return true;
        return false;
    }  
}

int main(){
    vector<int> v = {6,4,5,2,25,7,8} ;
    for(int i = 0;i<v.size();i++){
        for(int j =i+1;j<v.size();j++){
            if(s_i_s(v[i],v[j])){swap(v[i],v[j]);}
        }
    }
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<pair<int,int>> p = {{4,3},{5,5},{5,3},{25,6},{8,5}} ;
    // sort(p.begin(),p.end()) ;//ye inbuilt hai.
    for(int i = 0;i<p.size();i++){
        for(int j =i+1;j<p.size();j++){
            if(sh_i_s(p[i],p[j])){swap(p[i],p[j]);}
        }
    }
    for(int i = 0;i<p.size();i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    
}