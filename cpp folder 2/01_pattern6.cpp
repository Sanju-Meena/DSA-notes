#include<iostream>
using namespace std;
// *
// **
// ***
// ****
// *****
int main(){
 int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int i =1 ;
    int k = 1 ;
    while(i<=n){
         int j = 1 ;
        while(j <= k){
            cout<< "*" ;
            j++ ;
        }
        cout<<"\n";
        k++ ;
        i++ ;
    }
}