#include<iostream>
using namespace std;
//       1
//     2 3
//   4 5 6
// 7 8 9 10
int main(){
      int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int i=1;
    int k = 1 ;
    int value = 1 ;

    while(i<=n){
        int j = 1;
        while(j<n-i+1){
            cout<<"  ";
            j++ ;
        }
        int k = 1 ;
        while(k<=i){
            cout<<value<<" ";
            k++;
            value++;
        }
        i++;
        cout<<endl;
    }
}