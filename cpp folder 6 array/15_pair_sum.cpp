#include<iostream>
using namespace std ;

int main(){
    int n = 10,k=0;
    int arr[n] = {1,2,3,4,5,6,7,9,8,0} ;
    // find no. of pair whose sum is 10.
    int sum = 5;
    for(int i = 0;i<n;i++){
            int sum = 10;
        for(int j = 0;j<n;j++){
            if(arr[i] + arr[j] == sum && i!=j){
               if(arr[i] < arr[j]) {cout<<arr[i]<<" "<<arr[j]<<endl;}
                k++;
            }
        }
    }
    cout<<"no. of pair is "<<(k+1)/2;

}