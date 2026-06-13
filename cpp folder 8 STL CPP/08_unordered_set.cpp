#include<bits/stdc++.h>
using namespace std;
// yaha only change in TC that is equal to O(1) in all operation ;
// it is same as unordered map.
// main difference is , it does not hold entity in sorted way , it hold entity in random way;
void print(unordered_set<string> sd){
    for(string it : sd){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
   unordered_set<string> s;
    s.insert("asd");
    s.insert("df");
    s.insert("adss");
    s.insert("asd");
    print(s);
    auto it = s.find("asd") ;
    if(it != s.end()){cout<<*it<<endl;}

    s.erase("df") ;
    s.erase(it) ;
    print(s);

}