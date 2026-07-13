#include<iostream>
using namespace std;

// *****
//  ****
//   ***
//    **
//     *
int main(){
    int n ;
    cout<<"enter the value of n"<<endl;
    cin>>n ;
    int i = 1 ;
    while(i<=n){
        int j = 1;
        while(j<=n-i+1){
            cout<<"*" ;
            j++ ;
        }
        cout<<endl;
        int k =1;
        while(k<=i){
            cout<<" ";
            k++ ;
        }
        i ++ ;
    }
}