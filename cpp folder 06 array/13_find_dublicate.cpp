#include<iostream>
using namespace std ;

int main(){
    int n = 10,f=1;
    int arr[n] = {1,2,3,4,5,6,7,9,8,9} ;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<10;j++){
          if(arr[i] ==arr[j] && i!=j){
            cout<<"i = "<<i<<" j = "<<j<<endl;
            cout<<"unique no. is "<<arr[i]<<endl;
            f=0 ;
            break;
          }
        }
        if(f==0){break;}
}
}