#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the value of a\n";
    cin>>n ;
    int a =0;
    int b=1;
    cout<<a<<" "<<b<<" " ;
    for(int i=3 ;i<=n;i++){
        int c = a + b ;
        cout<<c <<endl;
        a=b ;
        b=c ;
    }
}