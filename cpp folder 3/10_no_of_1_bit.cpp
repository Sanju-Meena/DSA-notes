#include<iostream>
using namespace std;

int main(){
    int n  ;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int original_n = n ;
   int num = 0 ;
   int i = 1;
    while(n>0){
        int a = n % 2;
        num = num + a *i ;
        n = n/2 ;
        i*=10 ;
    }

    cout<<num<<endl ;

    int count = 0;
    while(num>0){
        int b = num%10;
        if(b==1){
          count +=1 ;
        }
        num = num/10 ;
    }
    cout<<"no. of 1 bit in the given n0. is " <<count ;
}