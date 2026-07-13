#include<iostream>
using namespace std;
// check weather the no. is prime or not.
int main(){
    int n;
    cout<<"enter the value of n\n";
    cin>>n; 
    int i = 2,prime = 0;
    while(n>i){
        if(n%i==0){
            prime = 1;
            exit ;
        }
        i++ ;
    }
    if(n<2){cout<<"not prime"<<endl ;}
    else if(prime==1){cout<<"Not prime";}
    else{cout<<"prime";}
}