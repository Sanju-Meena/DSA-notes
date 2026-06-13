#include<bits/stdc++.h>
using namespace std;

/* 1. TC unordered map k case mai (O(1)) hoti hai jitne hamne map mai function padhe hai unmai.
   2. Unordered map mai print ka order acc. to it's # value.
   3. Unordered map mai hum only ye datatype(int, float, double,long long, string ) enter kr sakte hai only.  */

void printmap(unordered_map<int,string> &m){
     for(auto val : m){
        cout<<val.first<<" "<<val.second<<endl;
    }
    cout<<endl;
}

int main(){
    unordered_map<int,string> m;
    m[1] = "priyanka" ; //TC = O(1) ;
    m[5] = "kajal" ;
    m[3] = "mahi" ;
    m[2]; 
    m[3];
    m.insert({4,"samiksha"});
    m[4] = "somi" ;
    cout<<m[1]<<endl;
    printmap(m) ;

    auto it = m.find(6); // TC = O(1);
    if(it == m.end()){cout<<"no value\n";}
    else{cout<<it->first<<" "<<it->second<<endl;}
    auto is = m.find(5);
    if(is == m.end()){cout<<"no value\n";}
    else{cout<<is->first<<" "<<is->second<<endl;}
    cout<<endl;

    m.erase(4);// TC = O(1);
    printmap(m) ;
    auto poi = m.find(3) ;
    m.erase(poi) ;
    printmap(m);
    m.clear() ;
    printmap(m);
    
    // multimap mai dublicate bhi store kr sakte hai means ek key pr 2 value;
    }