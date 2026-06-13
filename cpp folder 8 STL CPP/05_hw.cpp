#include<bits/stdc++.h>
using namespace std;
//given n string,print unique string in dictonary order with their frequency.
//  abc def abc ghj jkl ghj ghj abc
void printmap(map<int,string> &m){
     for(auto val : m){
        cout<<val.first<<" "<<val.second<<endl;
    }
    cout<<endl;
}
int main(){
    map<string,int> m; 
    int k;
    cout<<"no. of string : ";
    cin>>k;
    cout<<"write all n string\n ";
    // for (int i = 0; i < k; i++){
    //     string s;
    //     cin>>s;   
    //     m[s] = m[s] + 1;//m[s]++ ; bhi kr sakte the.      
    // }
    for (int i = 1; i <= k; i++){
        string s;
        cin>>s;  
        m[s] = i ;  
    }
    for(auto it : m){
    cout<<it.first<<" "<<it.second<<endl;
    }
    }