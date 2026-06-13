#include<iostream>
using namespace std;
void occurance(int arr[],int size,int qw[]){
  
for(int i = 1;i<=size;i++){
    for(int j = 0;j<size;j++){
        if(qw[j] == i){cout<<arr[j]<<" comes "<<i<<" times."<<endl;}
    }
}
  
}
int main(){
    int n;
    cout<<"enter the array size : ";
    cin>>n ;
    int arr[n] ;
    for(int i = 0;i<n;i++){
           cin>>arr[i];
           cout<<" " ;
    } 

   int qw[n] ;
   for(int i = 0;i<n;i++){
       int c = 0 ;
    for(int j = 0;j<n;j++){
       if(arr[i] == arr[j]){ 
          c = c+ 1;
       }
    }
    qw[i] = c;
   }
    //    for(int i = 0;i<n;i++){
    //        cout<<qw[i] <<" ";
    // }
    cout<<endl;
occurance(arr,n,qw);
}