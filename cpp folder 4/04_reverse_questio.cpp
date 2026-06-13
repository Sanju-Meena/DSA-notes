#include<iostream>
#include<math.h>
using namespace std ;

int main(){
int n ;
cout<<"enter then value of n\n";
cin>>n ;
int rev = 0;

for( ; n!=0 ; ){
   int a = n% 10 ;
    rev = rev*10 + a;
    n = n /10 ;
}
if(rev>(pow(2,31)-1) & rev<(-(pow(2,31)))){
    return 0;
}
else{
cout<< rev ;
}
}          
