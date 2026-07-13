#include<iostream>
using namespace std;
//  check karna hai ki kisi array ki value 1 k barabar hai ya nahi.

void search(int kaj[] , int n){
    int t =0;
    for(int i = 0;i<n;i++){
        if(kaj[i] == 1){
        t=1 ;
        break ;
        }
    }
    if(t==1)cout<<"1 is present.";
    else cout<<"1 is not present.";
} 


int main(){
    int arr[5] ;
    cout<<"enter the value arr[5]"<<endl;
    for(int i = 0;i<5;i++){
    cin>>arr[i] ;
    }
    search (arr , 5) ; 
    
}