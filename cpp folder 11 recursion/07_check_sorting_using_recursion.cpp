#include<iostream>
using namespace std;
// find weather the order of number is sorted or not using recursion;

bool issorted(int arr[],int n){
    int ans;
    if(n<2){return true;}
    else if(arr[0] > arr[1] ){
       return false;
    }
    else{
        ans = issorted(arr+1,n-1);
        //  return ans;
    }
    return ans;

}

int main(){
    int n = 5;
    // cin>>n;
    int arr[5];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<< issorted(arr,n);
}