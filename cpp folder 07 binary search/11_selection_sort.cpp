#include<iostream>
using namespace std;
// This method is used to arrange the no. in ascending or decending manner.
//pahele sabse minimum element ki index find karo and then 0 and minimum koo swap karo ; 
//TC = n!;
int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
          cin>>arr[i] ;
    }

     for(int i = 0;i<n-1;i++){
        int min = i ;
        for(int j = i+1;j<n;j++){
            if(arr[min] > arr[j]){
                min = j ;
            }
        }
      swap(arr[i], arr[min]) ;
    }  
    
    for(int i = 0;i<n;i++){
          cout<<arr[i]<<" " ;
    }
}