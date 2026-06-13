#include<iostream>
using namespace std ;

int main(){
    int n = 10,k=0;
    int arr[n] = {1,2,3,4,5,6,7,9,8,0} ;
    // find no. of triplet whose sum is 10.
    for(int i = 0;i<n;i++){
            int sum = 10;
        for(int j = 0;j<n;j++){
            for(int l=0;l<n;l++){
            if(arr[i] + arr[j]+arr[l] == sum && i!=j && j!=l){
               if(arr[i] < arr[j] && arr[j]<arr[l])
                {cout<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<endl;}
                k++;
            }
        }
        }
    }
    cout<<"no. of pair is "<<(k+1)/6;

}