#include<bits/stdc++.h>
#include<vector> 
using namespace std;

void printvec(vector<int> &v){ //yaha actual vector pass hota hai copy nahi.
    for(int i = 0 ;i < v.size() ; i++ ){
        cout<<v[i]<<" ";
    }
    v.push_back(7) ;
    cout<<endl;
}

int main(){ 
    vector<int> brr; 
    // hum angular bracket k ander float,double,pair bhi likh sakte hai.
    brr.push_back(0) ;
    //size show the exact no. of element in vector .
    // capacity show the memory that can hold the vector so that we can store the element.
    int capa = brr.capacity() ;
    cout<<capa<<endl;
    cout<<brr.size()<<endl ;
    // int n;
    // cout<<"enter size " ;
    // cin>>n;
    // for(int i = 0;i<n;i++){
    //     int x;
    //     cout<<"enter "<<i<<" element ";
    //     cin>>x;
    //     brr.push_back(x); // last mai ek value add kr dega.
    // }
    // printvec(brr);
    vector<int> v;
    v.push_back(8) ; 
    printvec(v) ;

    vector<int> ca(2,3) ;
    printvec(ca) ;
    ca.push_back(9) ;
    // ca.push_front(9) ; not applicable.
    printvec(ca) ;
    ca.pop_back();//last value delete & TC = O(1) ; .
    printvec(ca);

    //yaha copy nahi jayage yaha exact location jayage.
    vector<int> &oi = ca ; //TC = O(n) ;
    oi.push_back(54) ;
    printvec(oi) ;
    printvec(ca) ;

    vector<string> st; //vector of string hai not character.
    int size;
    cout<<"enter the size of string :" ;
    cin>>size;

    for(int i = 0; i < size;i++){
          string fd ;
          cout<<"enter string "<<i<<" : ";
          cin>>fd ;
          st.push_back(fd) ;
    }
    
    for(int i = 0; i< size;i++){
          cout<< st[i]<<" ";
    }
}