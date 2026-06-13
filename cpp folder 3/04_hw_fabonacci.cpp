#include<iostream>
using namespace std;
// 0,1,1,2,3,5,8,13,21,34...
int main(){
    int n ;
    cout<<"enter the term no. where you have to stop\n";
    cin>> n ;
    
     int arr[1000] ;
          arr[0] = 0 ;
          arr[1] = 1;
        cout<<arr[0]<<" ";
        cout<<arr[1]<<" ";

    for(int i=2 ; i<n ;i++ ){

         arr[i] = arr[i-2] + arr[i-1] ;
        cout<<arr[i]<<" ";
          
    }

}