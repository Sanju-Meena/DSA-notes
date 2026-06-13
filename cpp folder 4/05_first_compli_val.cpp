#include<iostream>
using namespace std ;

int main(){
int  n ;
cout<<"enter then value of n\n";
cin>>n ;

int m = n ;
int mask = 0; 
if (m ==0){
int  ans = 1;
}
while (m!=0)
{
  mask = (mask<<1) |1 ;
  m = m>>1;
}
int ans = (~n) & mask ;
cout<<ans ;
}    

// if n =5 --> 000..0101
// ~n = ------>111..1010 tot print ~a tke 2's compliment.
// mask create-000..0111. and take and of ~n and mask.