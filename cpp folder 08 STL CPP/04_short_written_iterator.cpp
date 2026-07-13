#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> as = {1, 2, 3, 4, 5};
    // Range based loop;
    for(int value : as){ //vector as[0] ki value copy hui hai.
        cout<<value<<" ";
    }
    cout << endl;
    for(int &value : as){
        value++ ;
    }
    for(int value : as){
        cout<<value<<" ";
    }
    cout << endl;

    vector<pair<int,int>> pa = {{1,2},{3,4},{5,6}} ;
    for(pair<int,int> value : pa){
        cout<<value.first<<" "<<value.second<<endl;
    }
    // --------------------------------------------------------------------------.
    cout<<endl;
    auto a = 8.4; //auto keyword automatically datatype ko find kr leta hai.
    cout<<a<<endl;

    vector<int> asd = {5,6,1,4,2}; 
    // for(auto it = asd.begin();it != asd.end();it++){
    for(auto value : asd){
        cout<<value<<" ";
    }
    cout<<endl;
    vector<pair<int,int>> kajal = {{1,2},{3,4},{5,6}} ;
    for(auto value : kajal){
        cout<<value.first<<" "<<value.second<<endl;
    }
}