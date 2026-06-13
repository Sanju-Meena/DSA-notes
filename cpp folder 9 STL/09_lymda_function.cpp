#include<bits/stdc++.h>
using namespace std;
// we learn all of,any off and none of, all are bool function.
int main(){
    // lymda function syntex;
   auto sum = [](int x,int y){ //function name 'sum',x,y pass
        int c = x+y;
        return c;
    }; 
    cout<<sum(2,3)<<endl;
    
    // let's start with all of;
    vector<int > v = {2,-3,5,0};
    cout<< all_of(v.begin(),v.end(),[](int x){return x>0;})<<endl ;
    cout<< any_of(v.begin(),v.end(),[](int x){return x<0;})<<endl ;
    cout<< none_of(v.begin(),v.end(),[](int x){return x==0;})<<endl ;
   // none of mai koi bhi match nahi karega too ye 1 return karega.

}