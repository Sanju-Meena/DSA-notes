#include <iostream>
using namespace std;

void fibo(int n){
    int a=0, b =1;
    int term =2, c;

    if(n==1){cout<<"0";}

    else if(n==2){cout<<"1";}
    else if(n>2){
    for(int i = 3;i<=n;i++){
        c = a+b;
        // cout<<c<<endl;
        term++;
        a=b;
        b=c;
    }
    cout<<"The value of "<< n << "th term is "<<c<<endl;
}
}
int main(){
    int n ;
    cout<<"enter the value of n\n";
    cin>>n;
    fibo(n);
}