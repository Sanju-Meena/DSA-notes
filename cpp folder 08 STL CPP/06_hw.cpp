#include<bits/stdc++.h>
using namespace std;
// erase element which are muntiple of three.
int main(){
  vector<int> v = {0,1,2,3,4,5,6,7,8,9} ;

    for(int i = 0 ; i<v.size();i++){
      if(v[i] % 3 == 0 && v[i] != 0){
        v.erase(v.begin() + i);
      }
    }

    for(int i : v){
      cout<<i<<" ";
    }
    
}