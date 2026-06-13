#include<bits/stdc++.h>
using namespace std;
// All have time complexcity O(n);

void arry(int v[],int n){
     auto it = min_element(v + 3,v+6);    
    cout<<*it<<endl;
    auto pointer = max_element(v,v+6-3);      
    cout<<*pointer<<endl;
    int sum = accumulate(v,v+6,-5);   
    cout<<sum<<endl;
    int ct = count(v,v+6-1,6); 
    cout<<ct<<endl;

    // check weather element present or not;
    auto fd = find(v,v+6,1); 
    if(fd == v+6){cout<<"element not present\n";}
    else{cout<<*fd <<" is present"<<endl;}

    //reverse a vector;    
    string st[4] = {" parianka"," meena"," weds"," sanjay"};
    reverse(st,st+4); 
    for(auto ir :st){cout<<ir;} cout<<endl;

}
int main(){
    vector<int> v = { 2,3,1,6,7,6};
    auto it = min_element(v.begin() + 3,v.end());    
    // int it = *min_element(v.begin(),v.end()); //ye bhi valid hai .
    cout<<*it<<endl;
    auto pointer = max_element(v.begin(),v.end()-3);      
    cout<<*pointer<<endl;
    int sum = accumulate(v.begin(),v.end(),0);    //initial sum humne zero diya hai.  
    cout<<sum<<endl;
    int ct = count(v.begin(),v.end()-1,6);  //no. of occour of 6.
    cout<<ct<<endl;

    // check weather element present or not;
    auto fd = find(v.begin(),v.end(),1); 
    if(fd == v.end()){cout<<"element not present\n";}
    else{cout<<*fd <<" is present"<<endl;}

    // int fd = *find(v.begin(),v.end(),1); 
    // if(fd == *v.end()){cout<<"element not present\n";}
    // else{cout<<fd <<" is present"<<endl;}

    //reverse a vector;    
    vector<string> st = {" sanjay"," meena"," weds"," priyanka"};
    reverse(st.begin(),st.end()); 
    for(auto ir :st){cout<<ir;} cout<<endl;

    string s = "kajal";
    reverse(s.begin()+2,s.end());
    cout<<s<<endl;

    int arr[6] = { 2,3,1,6,7,6};
    arry(arr,6);
 }