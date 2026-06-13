#include<iostream>
using namespace std;

void maxi (int kaj[] , int n){
    int maxi = kaj[0] ;
    for(int i = 0;i<n;i++){
        maxi = max(maxi , kaj[i]);
    }
    cout<<maxi<<endl;
} 

void update(int arr[], int n)
{

  int start = 0;
  int end = n - 1;
  while (start <= end)
  {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}
int main(){
    int n = 5;
    int arr[5]= {1,2,3,4,5};
    maxi(arr,n);
    
    
}