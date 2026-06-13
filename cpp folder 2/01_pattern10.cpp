#include<iostream>
using namespace std;
// A A A A
// B B B B
// C C C C
// D D D D like this.
int main(){

char ch = 'A' ;
  int n;
    cout<<"Enter the value of n\n";
    cin>>n;
int i =1 ;
while(i<=n){
    int j = 1;
    while(j<=n){
        cout<<ch <<" " ;
        j++ ;
    }
    i++ ;
    cout<<"\n";
    ch++;
}
}