#include<iostream>
using namespace std;
// D
// C D
// B C D
// A B C D like this.
int main(){

char ch = 'D' ;
  int n;
    cout<<"Enter the value of n\n";
    cin>>n;
int i =1 ;
while(i<=n){
    int j = 1;
    while(j<=i){
        cout<<ch <<" " ;
        j++ ;
        ch++ ;
    }
    cout<<"\n";
    ch = ch - i -1;
    i++ ;
}
}