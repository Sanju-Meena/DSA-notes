#include<iostream>
using namespace std ;

int main(){
int n = 5 ;
int ans = 0 ;
for(int i = 1;n!=0;i*=10){

   int digit = n%10 ;
   ans = ans + digit * i ;

 n = n >> 1 ;
}
cout<<ans;
}