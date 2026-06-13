#include<iostream>
using namespace std;
// 111
// 222
// 333.. ismai 

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int i=0;
while(i<n){
     int j = 0;
    while(j<n){
        cout<<i+1;
        j++ ;
    }
    cout<<"\n";
    i++;
}
}