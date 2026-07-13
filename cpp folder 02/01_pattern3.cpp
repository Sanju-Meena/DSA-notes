#include<iostream>
using namespace std;
// draw pattern like this
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int i =1 ;
    while(i<=n){
         int j = 1 ;
        while(j <= n){
            cout<< j;
            j++ ;
        }
        cout<<"\n";
        j = 1 ;
        i++ ;
    }
    }