#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the value of n\n";
    cin>>n; 
    int i =0,sum = 0;
    while(n>=i){
        sum+=i ;
        i++ ;
    }
    cout<<"sum of n number is "<<sum;
}