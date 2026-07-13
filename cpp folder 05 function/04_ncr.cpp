#include <iostream>
using namespace std;

int ncr(){
int n,r,a,b,c;
cout<<"value of n and r\n";
cin>>n>>r;
a = b = c =1;
// a mai n! , b mai r! and c mai (n-r)! store hoga.

for(int i=1;i<=n;i++){
    a= a *i ;}

for(int i=1;i<=r;i++){
    b= b *i ;}

for(int i=1;i<=n-r;i++){
    c = c *i ;}

    int ans =( a /(b*c) );
  
          return ans;
}
int main(){
  int p = ncr();
  cout<<p<<endl;
}