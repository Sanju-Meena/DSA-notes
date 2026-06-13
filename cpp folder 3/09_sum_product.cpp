#include<iostream>
using namespace std;

int main(){
    int n  ;
    cout<<"enter the value of n"<<"\n";
    cin>>n;
    int num = n;
    int sum =0;
    while(n>0){
        int a =n %10;
        sum+=a;
        n = n/10 ;
    }
    
    cout<<"sum = "<<sum<<endl;
    n = num ;
      int product =  1;
    while(n>0){
        int a =n %10;
        product*=a;
        n = n/10 ;
    }
  cout<<"differenceof product and sum is "<<(product - sum );
}