#include<iostream>
using namespace std;
//   - - - 1 - - -  
//   - - 1 2 1 - -  
//   - 1 2 3 2 1 -  
//   1 2 3 4 3 2 1   like this.

int main(){
    int n ;
    cout<<"Enter the value of n\n";
    cin>>n;

    int i = 1 ;

    while(i<n){
        int j=1;
        while(j<n-i+1){
            cout<<"  " ;
            j++;
        }
        int k = 1;
        while(k<=i){
            cout<<k<<" ";
            k++ ;
        }
        k-=2; 
        while(k>0){
            cout<<k<<" ";
            k--;

        }
         cout<<endl;
        i++;
    }

}