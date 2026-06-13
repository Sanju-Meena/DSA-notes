#include<iostream>
using namespace std;
// easy way to draw the star pattern.
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
    while(i<=n){
         int j = 1 ;
        while(j <= i){
            cout<< "*" ;
            j++ ;
        }
        cout<<"\n";
        i++ ;
    }
}