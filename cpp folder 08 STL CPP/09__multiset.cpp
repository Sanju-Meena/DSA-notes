#include<bits/stdc++.h>
using namespace std;
// print dublicate also and print in unordered way.
void print(multiset<string> sd){
    for(string it : sd){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
   multiset<string> s;
    s.insert("asd"); //O(log(n)) ;
    s.insert("df");
    s.insert("df");
    s.insert("df");
    s.insert("adss");
    s.insert("asd");
    print(s);
    auto it = s.find("asd") ;//O(log(n)) ; or ye pahele value ka iterator return karega .
    if(it != s.end()){cout<<*it<<endl;}
    s.erase(it) ; //dublicate hoo too 1st dublicate ko delete karega.
    print(s);
    s.erase("df") ; //dublicate hoo too self and all dublicate ko delete karega.
    print(s);
    auto iyt = (--s.end()) ; //this is the way to fing last operator.
    cout<<(*iyt)<<endl;
}