#include<iostream>
using namespace std;
// 123
// 456
// 789 draw pattern .
int main(){
      int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int i =1 ;
    int k = 1;
    while(i<=n){
        int j = 1 ;
        while(j <= n){
            cout<< k<<" ";
            j++ ;
            k++ ;
        }
        cout<<"\n";
        i++ ;
    }
}