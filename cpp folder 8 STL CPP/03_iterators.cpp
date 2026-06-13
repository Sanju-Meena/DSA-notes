#include<bits/stdc++.h>
using namespace std;
// iterators is used to point address.
int main(){
    vector<int> as = {1,2,3,4,5} ;
    for(int i = 0;i<as.size();i++){
        cout<<as[i]<<" ";
    }
    cout<<endl;
    //how to declare iterator;
    vector<int> ::iterator it = as.begin();
    cout<<*it <<endl;
    cout<<(*it+1) <<endl;
    for(it = as.begin();it != as.end();it++){
        //as.begin() first element k address ko point karta hai.
        //as.end() next of last element k address ko point karta hai.
        // it +1 ; it is valid for vector not for maps.
        // bcz in map element is allocated in non-contigious memory. 
        cout<<(*it)<<" ";
    }
    cout<<endl;

    vector<pair<int,int>> pa = {{1,2},{3,4},{5,6}} ;
    for(int i =0;i<pa.size();i++){
        cout<<pa[i].first<<" "<<pa[i].second<<endl;
    }
    vector<pair<int,int> > ::iterator pt ;
    for(pt = pa.begin();pt != pa.end();pt++){
        cout<<(*pt).first<<" "<<(*pt).second<<endl;
    }
    cout<<endl;
    // aisa bhi likh sakte hoo.
    for(pt = pa.begin();pt != pa.end();pt++){
        cout<<pt->first<<" "<<pt->second<<endl;
    }
}