#include<iostream>
using namespace std;
// A 
// B B
// C C C
// D D D D like this.
int main(){

char ch = 'A' ;
  int n;
    cout<<"Enter the value of n\n";
    cin>>n;
int i =1 ;
while(i<=n){
    int j = 1;
    while(j<=i){
        cout<<ch <<" " ;
        j++ ;
    }
    i++ ;
    ch++ ;
    cout<<"\n";
    
}
}