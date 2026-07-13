// sum of n even no.
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the value of n\n";
    cin>>n; 
    int i =0,sum = 0;
    while(n>=i){
        sum+=i ;
        i+=2 ;
    }
    cout<<"sum of n number is "<<sum;
}