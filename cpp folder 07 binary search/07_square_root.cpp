#include<iostream>
using namespace std;

int main(){
int x ;
cout<<"Enter he value of x : ";
cin>>x;
int i = 2,ans;
while(i<=x/2){
    if(i*i<=x){
        ans = i;
    }
    i++;
}
cout<<ans;
}