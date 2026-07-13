#include<bits/stdc++.h>
using namespace std;
// vector of pair $ vec of array.
void printvec_pair(vector<pair<int,int>> v){
    cout<<"size "<< v.size()<<endl;
    for(int i = 0 ;i < v.size() ; i++ ){
        cout<<v[i].first <<","<<v[i].second<<endl;
    }
}

int main(){ 
    // vector of pair mtlb pairs of value ko vector mai store karna.
    vector<pair<int,int> > l = {{1,2} , {3,4},{4,5} } ;
    printvec_pair(l) ;
    vector<pair<int,int> > m;
    int n;
    cout<<"enter size of vector of pair : " ;
    cin>>n;
    for(int i = 0 ;i < n; i++ ){
            int a,b;
            cout<<"enter element in pair "<<i<<" "<<endl ;
            cin>>a>>b;
            m.push_back({a,b}) ;
            // m.push_back(make_pair(a,b)) ;
    }    
    printvec_pair(m) ;

    vector<pair<int,int>> v = {{2,5},{1,7},{2,3},{1,2},{3,4}};
    // sort(v.begin(), v.end());  // Default sorting
    stable_sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.first < b.first; });
    for(auto &p : v) {
        cout << "(" << p.first << "," << p.second << ") ";
}
      
}