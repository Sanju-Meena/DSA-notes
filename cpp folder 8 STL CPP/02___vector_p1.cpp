#include<iostream>
#include<vector>
using namespace std;
//Vector is a array of variable size, initially it's size is 0.
//yadi tum locally vector declare karte ho too size 10^5 element store kr sakte hoo.
//yadi tum globally vector declare karte ho too size 10^7 element store kr sakte hoo.
//online programing website pr, laptop pr mai be different hoo sakti hai;
// this limit is due to contigious memory allocation on laptop;

void printvec(vector<int> v){
    //for(int i : v){
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" " ;
    }
    cout<<endl;
}

int main(){
    vector<int> ar = { 1,2,3}; 
    printvec(ar) ;
    //vector<int> arr ;//vector of int;
    vector<int> p(5) ;    
    printvec(p) ;
    p.push_back(3) ;
    printvec(p) ;

    vector<int> arr ;
    int n; cout<<"enter size of vector : ";
    cin>>n;
    for(int i = 0;i<n;i++){
    printvec(arr) ;
    cout<<"size : "<< arr.size()<<"  "; //TC = O(1) ;
    cout<<"capacity : "<< arr.capacity()<<endl; //TC = O(1) ;
    int send;  
    cout<<"enter element : ";
    cin>>send;
    arr.push_back(send) ; //TC = O(1); vector k end mai value save karta hai.
    }
    printvec(arr) ;
    cout<<"size : "<< arr.size()<<" ";
    cout<<"capacity : "<< arr.capacity()<<endl;

    arr.pop_back();  // O(1); ye last value ko delete karta hai.
    printvec(arr) ;
    vector<int> asd = arr ; //TC = O(n) ; and asd copy hai actual nahi;
    asd.push_back(6) ;
    printvec(asd) ;
    printvec(arr) ;
    arr.clear() ;
    printvec(arr) ;
    printvec(asd) ;
    cout<<"size : "<< arr.size()<<" ";
    cout<<"capacity : "<< arr.capacity()<<endl;
    
    arr[2] = 9 ;
    cout<<arr[0]<<" " <<arr[1]<<" ";
    cout<<arr[2]<<" " <<endl;    
    cout<<"size : "<< arr.size()<<" ";
    cout<<"capacity : "<< arr.capacity()<<endl;
    
}