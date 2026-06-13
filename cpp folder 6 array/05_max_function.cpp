#include<iostream>
#include<climits>
using namespace std;

int maxi (int kaj[] , int n){
    int maxi = kaj[0] ;
    for(int i = 0;i<n;i++){
        maxi = max(maxi , kaj[i]);
    }
    return maxi ;
} 


int main(){
    int arr[5] ;
    cout<<"enter the value of arr[5]"<<endl;
    for(int i = 0;i<5;i++){
        cin>>arr[i] ;
    }
    int large = maxi(arr,5) ;
    cout<<large ;
    
}