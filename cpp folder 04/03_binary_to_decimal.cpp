#include<iostream>
using namespace std ;

int main(){
int n ;
cout<<"enter the value of binary no. \n";
cin>>n ;
int decimal = 0 ;

for(int i = 1;n!=0;i = i*2){
   int digit = n%10 ;
   decimal = decimal + digit*i ;
   n = n/10 ;
}

cout<<"decimal no. is "<<decimal;
}          
