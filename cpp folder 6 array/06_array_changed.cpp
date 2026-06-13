#include<iostream>
using namespace std;

void print_array(int array[],int n){
    for(int i = 0;i<n;i++){
      cout<<array[i]<<" " ;
    }
    cout<<endl;
}

void update(int arr[] , int n){
  arr[1] = 8;
  print_array(arr,n) ;
}

int main(){
  int n = 3;
  int arr[3] = {2,4,6} ;
  print_array(arr,n) ;
  update(arr , 3); //hamne arr written kr k address diya hai update function ko arr ka.
  print_array(arr,n) ;

}