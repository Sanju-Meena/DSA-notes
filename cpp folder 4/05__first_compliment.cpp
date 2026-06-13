#include<iostream>
using namespace std ;

int main(){
int n ;
cout<<"enter then value of n\n";
cin>>n ;
int num =0 ;
int i = 1;
while(n!=0){
    int a = n&1 ;
    num = num +a*i ;
    n = n/2;
    i = i*10;
}
cout<<num <<endl; 
int j = 1;
int  com = 0 ;
while(num!=0){
int a=0;
a = num%10;
if(a==1){
    a =0;
    com = com + a*j ;
    num = num/10;
    j = j*10;
}else{
     a =1;
     com = com + a*j ;
     num = num/10;
     j = j*10;
    }
 }     
cout<<com<<endl ;
int sec = com;
int digit = 0 ; 
int k = 1 ;
while(sec!=0){
    int g = sec % 10 ;
    digit = digit + g*k ; 
    sec = sec/10 ;
    k = k*2; 
}
cout<<digit ;
}    
