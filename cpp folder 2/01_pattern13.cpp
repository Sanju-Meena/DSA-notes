#include<iostream>
using namespace std;
// A B C
// B C D
// C D E like this.
int main(){

char ch = 'A' ;
  int n;
    cout<<"Enter the value of n\n";
    cin>>n;
int i =1 ;
while(i<=n){
    int j = 1;
    while(j<=n){
        cout<<ch<<" " ;
        j++ ;
        ch++ ;
    }
    i++ ;
    cout<<"\n";
    ch = ch - 3 ;
    
}
}