#include<iostream>
using namespace std;
// 1
// 2 2 
// 3 3 3
// 4 4 4 4 like this.
int main(){
int n ;
cout<<"enter the value of n\n";
cin>>n ;
int i =1 ;
while(i<=n){
    int j = 1;
    while(j<=i){
        cout<<i<<" " ;
        j++ ;
    }
    i++ ;
    cout<<"\n";
}
}