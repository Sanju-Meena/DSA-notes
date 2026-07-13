#include<iostream>
using namespace std;
// 1 2 3 4
//   2 3 4
//     3 4
//       4
 
int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int i=1;

    while(i<=n){
        int j = 1;
        while(j<=n-i+1){
            cout<< j+i-1 <<" ";
            j++ ;
        }
        cout<<endl;
        int k = 1;
        while(k<=i){
            cout<<"  " ;
            k++ ;
        }
        i++ ;
    }
}