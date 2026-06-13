#include<iostream>
using namespace std;
// A B C d
// A B C d
// A B C d
// A B C d like this.
int main(){

char ch = 'A' ;
  int n;
    cout<<"Enter the value of n\n";
    cin>>n;
int i =1 ;
while(i<=n){
    int j = 1;
    char ch = 'A' ;
    while(j<=n){
        cout<<ch <<" " ;
        j++ ;
        ch++ ;
    }
    i++ ;
    cout<<"\n";
    
}
}