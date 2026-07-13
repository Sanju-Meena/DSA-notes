#include <iostream>
using namespace std;

void update(int arr[], int n)
{
  // for(int i = 0; i<n/2;i++){
  //     int c = arr[i] ;
  //     arr[i] = arr[n-1-i] ;
  //     arr[n-i-1] = c ;

  // }

  int start = 0;
  int end = n - 1;
  while (start <= end)
  {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

int main()
{
  int arr[6] = {2,4,6,7,2,0};
  update(arr, 6);
  for (int i = 0; i < 6; i++)
  {cout << arr[i] << " ";}
}