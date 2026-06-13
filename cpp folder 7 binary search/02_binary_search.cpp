#include <iostream>
using namespace std;
// In a sorted array keys are present or not;
int binarysearch(int ev[], int size, int key)
{
     int s = 0;
     int e = size - 1;
     int mid = s + (e - s) / 2;

     while (s <= e){
          if (ev[mid] == key){
               return mid;
          }

          if (key > ev[mid]){
               s = mid + 1;
          }
          else{
               e = mid - 1;
          }
          mid = s + (e - s) / 2;
     }
     return -1;
}
// O(logn) iski time complexity km hai.
int main()
{

     int od[5] = {3, 8, 11, 14, 16};
     int ev[6] = {2, 4, 6, 8, 12, 14};

     int x = binarysearch(ev, 6, 4);
     cout << "index is : " << x << endl;
     int y = binarysearch(od, 5, 2);
     cout << "index is : " << y << endl;
}