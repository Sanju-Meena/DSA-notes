#include<iostream>
using namespace std;
//best method among three;
// compare each element(start with index 1) by previous one put on write palace and then again compare index 2; 
int insertion_array(int arr[],int size){

    for(int i  = 1;i<size;i++){
        int temp = arr[i] ;
        int j = i-1 ;
        for(;j>=0;j--){
            if ((arr[j] > temp)){
                arr[j+1] = arr[j] ;
                // for(int i = 0;i<size;i++){cout<<arr[i]<<" ";}cout<<endl;
            }
            else{break;}
        } 
        arr[j+1] = temp;
    }
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
} 

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i] ;
    }
     insertion_array(arr,n);
}