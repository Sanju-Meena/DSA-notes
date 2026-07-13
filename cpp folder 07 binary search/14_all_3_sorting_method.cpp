#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i] ;
    }
//   Normal sorting method ---> Find min indices swap it to 0 and do it again and again.
//     for(int j = 0;j<n-1;j++){
//     int min = j;
//     for(int i = j+1;i < n;i++){
//         if(arr[min] > arr[i]){
//             min = i ;
//         }
//     }
//    swap( arr[j] , arr[min]) ;
// }

  //  Bubble sorting method ---> In round 1 swap to no. with each other so last element comes it's right place.
  // for(int k = 0;k<n-1;k++){
  //   for(int i = 0; i < n-1 ; i++){
  //          int j = i + 1;
  //          if(arr[i]> arr[j]){
  //           swap(arr[i] , arr[j]);
  //          }
  //   }
  // }

  // insertion sort----> 1 element fix take next element and campare with previous one then put on the right place.

  for(int i = 1;i<n;i++){
     int temp = arr[i] ;
     int j = i-1 ;
    for(;j>-1;j--){
      if(arr[j] > temp){
          //  shift karo
        arr[j+1] = arr[j] ; }
      else{ break;}
    }
    arr[j+1] = temp;
  }

for(int i = 0;i<n;i++){cout<<arr[i]<<" ";}
}