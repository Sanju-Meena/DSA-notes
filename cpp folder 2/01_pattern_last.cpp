#include<iostream>
using namespace std;
// 1 2 3 4 5 5 4 3 2 1 
// 1 2 3 4 * * 4 3 2 1 
// 1 2 3 * * * * 3 2 1 
// 1 2 * * * * * * 2 1  
// 1 * * * * * * * * 1  like this.

int main(){
    int n ;
    cout<<"Enter the value of n\n";
    cin>>n;

    int i = 1 ;

    while(i<n){
        int j=1;
        while(j<n-i+1){
            cout<<j <<" ";
            j++;
        }
        int k = 1;
        while((k+1) < 2*i){
            cout<<"*"<<" ";
            k++ ;
        }
        j--; 
        while(j>0){
            cout<<j<<" " ;
            j--;

        }
         cout<<endl;
        i++;
    }

}