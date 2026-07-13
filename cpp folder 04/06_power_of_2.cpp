#include<iostream>
using namespace std ;

int main(){
int n ;
cout<<"enter then value of n\n";
cin>>n ;
int check = 1;
if(n<=0 ){ cout<<"not a power of 2\n";}

while(n!=1){
    if(n%2==0){
        n = n/2 ;
        check = 1;
        continue ;
    }
    else{
        check = 0;
        break ;
    }
    }

    if(check ==0){   cout<<"not a power of 2\n"; }
    else{cout<<"no. is a power of 2\n"; }
}
// method 2 is to compare all 2 ki powers with n with the help of power function.
// by for loop initialize i =0 to 31, and take 2 ki power. 
