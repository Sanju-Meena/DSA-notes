#include<iostream>
using namespace std;
//  print the prime no. between 1 to 100.

int main(){
    int n;
    cout<<"Enter the value of n \n" ;
    cin>>n  ;
    cout<<"*** prime no. btw 1 to "<<n<<"*** " <<endl;
    cout<<"2 " ;
    for(int a=3;a<=n;a++ ){
        int prime = 0 ;
    for(int i = 2 ;i<a ;i++){
        if (a % i== 0){
            prime= 1;
            break ;
        }
        else{
            continue ;
        }
    }
    if(prime == 1){
    }
    else{
        cout<<a << " " ;
    }
}
}