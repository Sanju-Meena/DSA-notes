#include <iostream>
using namespace std;

void prime(int n){
    int i = 2,prime =0;
    while(i<n){
        if(n%i==0){
            prime = 1;
            break;
        }
        i++;
    }
    if(prime == 0){cout<<"num is prime\n";}
    else{cout<<"num is not prime\n";}
}

int main(){
    int a;
    cout<<"enter the value of a\n";
    cin>>a;
    prime(a);
}
// function call stack mtlb jo chij pahele rakhi gai thi
// vo aakhari mai uthayenge.