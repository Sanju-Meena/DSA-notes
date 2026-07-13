#include<bits/stdc++.h>
using namespace std;
// set is similar to map but it does not store any value of specific key, it store only key.
// set print in sorted order.
// only store unique element.
// ismai bhi TC map ki jaise hoti hai O(log(n)) .
//ismai unique vlaue store hoti hai or erase karne mai jo unique value store thi vo delete hoti hai.
void printset(set<string> &st){
    for(auto it: st){ // yaha auto ki value string hai. 
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){
    set<string> s;
    s.insert("asd");
    s.insert("df");
    s.insert("df");
    s.insert("adss");
    s.insert("asd");
    s.insert("asd");
    s.insert("asd");
    printset(s);
    cout<<"Now do operation:\n";
    auto it = s.find("asd") ;
    if(it != s.end()){cout<<*it<<endl;}

    s.erase("df") ;
    printset(s) ;
    s.erase(it) ;
    printset(s);
}