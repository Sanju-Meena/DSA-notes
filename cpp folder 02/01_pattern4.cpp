#include<iostream>
using namespace std;
// 4321
// 4321
// 4321
// 4321 draw pattern like this.
int main (){
int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int i =1 ;
    while(i<=n){
        int j =1;
        while(j<=n){
            cout<<n-j+1 ;
            j++ ;
        }
        cout<<"\n" ;  
        i++;
  }
}