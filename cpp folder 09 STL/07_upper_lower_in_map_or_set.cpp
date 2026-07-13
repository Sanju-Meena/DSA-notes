#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> v ;//6, {4,5,5,25,7,8};
    int size ;
    cout<<"enter size of set : ";
    cin>>size;
    cout<<"Enter values in set ";
    for(int i =0;i<size;i++){
      int x;
      cin>>x;
      v.insert(x);
    }
    for(auto c : v){cout<<c<<" ";}
    cout<<endl;
    auto it = lower_bound(v.begin(),v.end(),25) ;
    cout<<*it<<endl;
    auto ir = upper_bound(v.begin(),v.end(),5) ;
    cout<<*ir<<endl;
    auto iu = upper_bound(v.begin(),v.end(),56) ;
    cout<<*iu<<endl;//aise use karne mai TC = O(n) hogi set ka case mai.

    cout<<endl;
    auto ptr = v.lower_bound(7);
    cout<<(*ptr)<<endl; //ismai TC = O(log(n)) hoti hai.
    

    map<int,int> m;
    m[2] = 4;
    m[4] = 5;
    m[5] = 4;
    m[8] = 6;
    m[6] = 8;
    m[2] = 0;
   for(auto d : m){cout<<d.first<<" "<<m[d.first]<<endl;}
    cout<<endl;
    auto tr = m.lower_bound(3);
    cout<<(*tr).first<<endl;  //op is 4;
 }