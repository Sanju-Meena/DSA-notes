#include<iostream>
using namespace std ;

int main(){
int n ;
cout<<"enter the value of n\n";
cin>>n ;
int binary = 0 ;
for(int i = 1;n!=0;){
   int bit = n&1 ;
   binary = binary + bit*i ;
//    if we give answer in reverse order then
//    binary = binary *10 + bit ;
   i = i*10 ;
//    n = n /2 ; 
 n = n >>1 ;
}
cout<<binary;
}
