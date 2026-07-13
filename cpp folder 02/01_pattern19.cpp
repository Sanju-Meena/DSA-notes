#include<iostream>
using namespace std;
// *****
// ****
// ***
// **
// *
int main(){
 int n;
    cout<<"Enter the value of n\n";
    cin>>n;
   int i = 1;
   while(i<=n){
    int j =1 ;
    while(j<=n-i+1){
        cout<<"*" ;
         j++ ;
    }
    cout<<endl ;
    i++ ;
   }
}