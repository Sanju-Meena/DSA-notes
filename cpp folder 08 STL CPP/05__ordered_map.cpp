#include<bits/stdc++.h>
using namespace std;
// map is a datastructure which store keys and according to keys it's value is stored.
// in normals map keys always store in sorted order or order given by red black trees means
// int datatype arrage in ascending order and string arrange in dictonary order.
// in unordered map value always store according to # value.
// dublicate value does store in map while it's ordered or unordered.
void printmap(map<int,string> &m){
     for(auto val : m){ 
        cout<<val.first<<" "<<val.second<<endl;
    }
    cout<<endl;
// map k exertion ki bhi TC = nlog(n) hoti hai.
}

int main(){
    map<int,string> m; //1 st datatype key and 2 is it's value.
    m[1] = "priyanka" ; //TC = O(log(n)) ;
    m[5] = "kajal" ;
    m[3] = "mahi" ;
    m[2]; //iski bhi TC O(log(n)) hogi ;but value string type hai too empty string aayegi or int hoti too 0 store hoti.
    //another way to fill value in map.
    m.insert({4,"samiksha"});
    m[4] = "saloni" ; //samiksha ko hata kr ye saloni store karega.
    m[3] = "srileela";
    printmap(m) ;

    auto it = m.find(6); // TC = O(log(n));
    if(it == m.end()){cout<<"no value\n";}//m.find take only key value.
    else{cout<<(*it).first<<" "<<(*it).second<<endl;}
    
    auto is = m.find(5);
    if(is == m.end()){cout<<"no value\n";}
    else{cout<<is->first<<" "<<is->second<<endl;}
    cout<<endl;

    m.erase(4);// TC = O(log(n));
    printmap(m) ;
    auto poi = m.find(3) ;
    m.erase(poi) ;
    printmap(m);
    m.clear() ;
    printmap(m);
    
    map<string,string > s;
    s["acde"] = " acde" ;  // TC = O(log(n)) * s.size();

    map<int, vector<int>> mp;
    // Create vector and insert
    mp.insert({1, {10, 20, 30}});
    for(int i = 0;i<5;i++){
        mp[2].push_back(i);
    }
    // mp.emplace(2, vector<int>{40, 50});
    for (auto &p : mp) {
        cout <<p.first<< " : ";
        for (auto val : p.second) cout << val << " ";
        cout << "\n";
    }
    
    }